/*
 * Copyright © 2024 Tim Herreijgers
 * Licensed using the MIT license
 */

#include "memory_mapped_file_parser.hpp"

namespace Model
{

MemoryMappedFileParser::MemoryMappedFileParser(std::string_view stringView) :
    m_stringView(stringView)
{
}

auto MemoryMappedFileParser::getNextLine() noexcept -> std::string_view
{
    const auto nextNewLine = m_stringView.find('\n', m_lastNewLine + 1) + 1;
    const auto line = nextNewLine != 0 ? m_stringView.substr(m_lastNewLine, nextNewLine - m_lastNewLine - 1) : m_stringView.substr(m_lastNewLine);
    m_lastNewLine = nextNewLine != 0 ? nextNewLine : m_stringView.size();
    return line;
}

auto MemoryMappedFileParser::hasNextLine() const noexcept -> bool
{
    return m_lastNewLine < m_stringView.size();
}

} // namespace Model