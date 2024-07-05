/*
 * Copyright © 2024 Tim Herreijgers
 * Licensed using the MIT license
 */
 
#pragma once

#include "observable_map.h"

#include "types/color.h"

#include <map>
#include <string>
#include <functional>

namespace Model
{

struct LogLevelColorSettings
{
    ObservableMap<std::string, Types::Color> textColor;
    ObservableMap<std::string, Types::Color> backgroundColor;
};

} // namespace Model