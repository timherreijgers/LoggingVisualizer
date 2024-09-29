/*
 * Copyright © 2024 Tim Herreijgers
 * Licensed using the MIT license
 */

#pragma once

#include "log_level_color_settings_entry.h"
#include "observable_vector.h"

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

    [[nodiscard]] auto getLogLevelColorSettings() noexcept -> ObservableVector<LogLevelColorSettingsEntry>&;
    void saveSettings();

private:
    SettingsManager();

    static void createYamlFile();
    void loadSettingsFromYamlFile();

    ObservableVector<LogLevelColorSettingsEntry> m_logLevelColorSettings;
};


} // namespace Model