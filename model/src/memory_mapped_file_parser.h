/*
 * Copyright © 2024 Tim Herreijgers
 * Licensed using the MIT license
 */

#pragma once

#include <string_view>

namespace Model
{

class MemoryMappedFileParser
{
public:
    explicit MemoryMappedFileParser(std::string_view stringView);

    [[nodiscard]] auto getNextLine() noexcept -> std::string_view;
    [[nodiscard]] auto hasNextLine() const noexcept -> bool;

private:
    std::string_view m_stringView;
    size_t m_lastNewLine = 0UL;
};

} // namespace Model