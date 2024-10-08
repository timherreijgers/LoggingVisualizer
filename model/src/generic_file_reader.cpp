/*
 * Copyright © 2024 Tim Herreijgers
 * Licensed using the MIT license
 */

#include "generic_file_reader.h"

#include "exceptions/FileNotFoundException.h"

#include <fmt/format.h>

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
}

void GenericFileReader::closeFile()
{
    if (m_file != nullptr)
    {
        fclose(m_file);
    }
}

auto GenericFileReader::exists() const noexcept -> bool
{
    return m_file != nullptr;
}

auto GenericFileReader::hasNextLine() -> bool
{
    if (getc(m_file) == EOF)
    {
        return false;
    }

    fseek(m_file, -1, SEEK_CUR);
    return true;
}

auto GenericFileReader::readNextLine() -> std::string
{
    std::array<char, 512> line{};
    m_couldReadFile = fgets(line.data(), 512, m_file) != nullptr;
    return line.data();
}

} // namespace Model