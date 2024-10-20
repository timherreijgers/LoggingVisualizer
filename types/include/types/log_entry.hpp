/*
 * Copyright © 2024 Tim Herreijgers
 * Licensed using the MIT license
 */

#pragma once

#include <string>

namespace Types
{

struct LogEntry
{
    std::string_view time;
    std::string_view level;
    std::string_view message;

    auto operator<=>(const LogEntry& other) const noexcept -> std::strong_ordering = default;
};

}; // namespace Types