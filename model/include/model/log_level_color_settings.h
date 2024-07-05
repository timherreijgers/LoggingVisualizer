/*
 * Copyright © 2024 Tim Herreijgers
 * Licensed using the MIT license
 */
 
#pragma once

#include "observable.h"

#include "types/color.h"

#include <map>
#include <string>
#include <functional>

namespace Model
{

struct LogLevelColorSettings
{
    std::map<std::string, Types::Color> textColor;
    std::map<std::string, Types::Color> backgroundColor;

    std::function<void()> settingChanged;
};

} // namespace Model