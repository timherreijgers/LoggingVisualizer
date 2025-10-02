/*
 * Copyright © 2024 Tim Herreijgers
 * Licensed using the MIT license
 */

#include "generic_file_reader.hpp"

#include "exceptions/FileNotFoundException.hpp"

#include <array>
#include <cstdio>

namespace Model
{

GenericFileReader::GenericFileReader() :
    m_file(std::fopen("", "r"), &fileDeleter)
{
}

void GenericFileReader::openFile(const std::filesystem::path& path)
{
    m_file = std::unique_ptr<std::FILE, decltype(&fileDeleter)>(std::fopen(path.string().c_str(), "r"), &fileDeleter);
    if (m_file == nullptr)
    {
        throw Exceptions::FileNotFoundException(path);
    }

    const auto hasNextLineInternal = [&]() -> bool {
        if (std::getc(m_file.get()) == EOF)
        {
            return false;
        }

        std::fseek(m_file.get(), -1, SEEK_CUR);
        return true;
    };

    std::array<char, 512> line{};
    while (hasNextLineInternal())
    {
        m_couldReadFile = std::fgets(line.data(), 512, m_file.get()) != nullptr;
        m_lines.emplace_back(line.data());
    }
}

void GenericFileReader::closeFile()
{
    m_file.reset();
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