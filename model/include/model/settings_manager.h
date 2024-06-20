/*
 * Copyright (c) 2024 Tim Herreijgers
 * Licensed using the MIT license
 */
 
#pragma once

#include "log_level_color_settings.h"

namespace Model::SettingsManager
{

[[nodiscard]] auto getLogLevelColorSettings() noexcept -> LogLevelColorSettings&;

} // namespace Model::SettingsManager