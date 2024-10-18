/*
 * Copyright © 2024 Tim Herreijgers
 * Licensed using the MIT license
 */

#pragma once

#include "types/color.h"

#include <string>

namespace Model
{

struct LogLevelColorSettingsEntry
{
    std::string level;
    Types::Color textColor;
    Types::Color backgroundColor;

    LogLevelColorSettingsEntry(std::string level, Types::Color textColor, Types::Color backgroundColor) :
        level(std::move(level)), textColor(textColor), backgroundColor(backgroundColor)
    {
    }
};

} // namespace Model