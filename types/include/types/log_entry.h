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
};

}; // namespace Types