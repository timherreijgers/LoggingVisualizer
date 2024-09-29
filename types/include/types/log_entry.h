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
    std::string time;
    std::string level;
    std::string message;
};

}; // namespace Types