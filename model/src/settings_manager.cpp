/*
 * Copyright (c) $originalComment.match("Copyright © (\d+)", 1, "-", "$today.year")$today.year. Tim Herreijgers
 * Licensed using the MIT license
 */

#include "model/settings_manager.h"
#include "model/log_level_color_settings.h"

namespace Model::SettingsManager
{

auto getLogLevelColorSettings() noexcept -> LogLevelColorSettings &
{
    static LogLevelColorSettings settings;
    return settings;
}

} // namespace Model::SettingsManager