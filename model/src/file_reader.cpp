/*
 * Copyright © 2024 Tim Herreijgers
 * Licensed using the MIT license
 */

#include "file_reader.h"

namespace Model
{

void FileReader::setPath(const std::filesystem::path& path) noexcept
{
    m_file = fopen(path.string().c_str(), "r");
}

auto FileReader::exists() const noexcept -> bool
{
    return m_file != nullptr;
}

auto FileReader::hasNextLine() -> bool
{
    return m_bytesRead != -1;
}

auto FileReader::readNextLine() -> std::string
{
    char * line = NULL;
    size_t len = 0;

    m_bytesRead = getline(&line, &len, m_file);
    return line;
}

} // namespace Model