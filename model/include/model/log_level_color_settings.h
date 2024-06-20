/*
 * Copyright (c) 2024 Tim Herreijgers
 * Licensed using the MIT license
 */
 
#pragma once

#include "types/color.h"

#include <map>
#include <string>

namespace Model
{

struct LogLevelColorSettings
{
    std::map<std::string, Types::Color> textColor;
    std::map<std::string, Types::Color> backgroundColor;
};

} // namespace Model