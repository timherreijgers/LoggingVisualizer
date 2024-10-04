/*
 * Copyright © 2024 Tim Herreijgers
 * Licensed using the MIT license
 */

#include "generic_file_reader.h"

#include <stdio.h>

namespace Model
{

void GenericFileReader::setPath(const std::filesystem::path& path) noexcept
{
    m_file = fopen(path.string().c_str(), "r");
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
    size_t len = 0;

    m_couldReadFile = fgets(line, 1024, m_file) != nullptr;
    return line;
}

} // namespace Model