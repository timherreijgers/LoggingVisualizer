/*
 * Copyright © 2024 Tim Herreijgers
 * Licensed using the MIT license
 */
 
#pragma once

#include "observable_map.h"
#include "observable_vector.h"

#include "types/color.h"

#include <map>
#include <string>
#include <functional>

namespace Model
{

struct LogLevelColorSettingsEntry
{
    std::string level;
    Types::Color textColor;
    Types::Color backgroundColor;
};

} // namespace Model