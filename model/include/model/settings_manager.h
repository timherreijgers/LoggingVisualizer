/*
 * Copyright (c) 2024 Tim Herreijgers
 * Licensed using the MIT license
 */
 
#pragma once

#include "log_level_color_settings.h"

namespace Model
{

class SettingsManager
{
public:
    SettingsManager(SettingsManager&) = delete;
    SettingsManager(SettingsManager&&) = delete;
    SettingsManager operator=(SettingsManager&) = delete;
    SettingsManager& operator=(SettingsManager&&) = delete;    

    [[nodiscard]] auto static instance() noexcept -> SettingsManager&
    {
        static SettingsManager instance;
        return instance;
    }

    [[nodiscard]] auto getLogLevelColorSettings() noexcept -> LogLevelColorSettings&;
private:
    SettingsManager();

    void createYamlFile();

    LogLevelColorSettings m_logLevelColorSettings;
};


} // namespace Model