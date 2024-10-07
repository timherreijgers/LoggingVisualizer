/*
 * Copyright © 2024 Tim Herreijgers
 * Licensed using the MIT license
 */

#include "generic_file_reader.h"

#include <fmt/format.h>

#include <cstdio>

namespace Model
{

void GenericFileReader::openFile(const std::filesystem::path& path)
{
    const auto result = fopen_s(&m_file, path.string().c_str(), "r");
    if (result != 0)
    {
        throw std::runtime_error(fmt::format("Failed to open file {}", path.string()));
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
    return m_couldReadFile;
}

auto GenericFileReader::readNextLine() -> std::string
{
    char line[512] = {0};

    m_couldReadFile = fgets(line, 512, m_file) != nullptr;
    return line;
}

} // namespace Model