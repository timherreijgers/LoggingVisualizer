/*
 * Copyright © 2024 Tim Herreijgers
 * Licensed using the MIT license
 */

#include "generic_file_reader.hpp"

#include "exceptions/FileNotFoundException.hpp"

#include <array>
#include <cstdio>
#include <fcntl.h>

namespace Model
{

void GenericFileReader::openFile(const std::filesystem::path& path)
{
    m_file = fopen(path.string().c_str(), "r");
    if (m_file == nullptr)
    {
        throw Exceptions::FileNotFoundException(path);
    }

    const auto hasNextLineInternal = [&]() {
        if (getc(m_file) == EOF)
        {
            return false;
        }

        fseek(m_file, -1, SEEK_CUR);
        return true;
    };

    std::array<char, 512> line{};
    while (hasNextLineInternal())
    {
        m_couldReadFile = fgets(line.data(), 512, m_file) != nullptr;
        m_lines.emplace_back(line.data());
    }
}

void GenericFileReader::closeFile()
{
    if (m_file != nullptr)
    {
        fclose(m_file);
    }

    m_lines.clear();
}

auto GenericFileReader::exists() const noexcept -> bool
{
    return m_file != nullptr;
}

auto GenericFileReader::hasNextLine() -> bool
{
    return m_index < m_lines.size();
}

auto GenericFileReader::readNextLine() -> std::string_view
{
    return m_lines[m_index++];
}

} // namespace Model