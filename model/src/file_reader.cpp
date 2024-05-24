/*
 * Copyright © 2024 Tim Herreijgers
 * Licensed using the MIT license
 */

#include "file_reader.h"

namespace Model
{

FileReader::FileReader(const std::filesystem::path & path)
    : m_stream(std::ifstream(path))
{
}

auto FileReader::exists() const noexcept -> bool
{
    return m_stream.is_open();
}

auto FileReader::hasNextLine() -> bool
{
    return m_stream.peek() != EOF;
}

auto FileReader::readNextLine() -> std::string
{
    std::string line;
    std::getline(m_stream, line);
    return line;
}

} // namespace Model