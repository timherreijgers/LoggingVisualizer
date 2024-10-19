/*
 * Copyright © 2024 Tim Herreijgers
 * Licensed using the MIT license
 */

#pragma once

#include "log_level_color_settings_entry.hpp"

#include "model/signal.hpp"

#include <vector>

namespace Model
{

using SettingsChangedSignal = Signals::signal<void()>;

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

    void setLogLevelColorSettings(std::string level, Types::Color textColor, Types::Color backgroundColor);
    [[nodiscard]] auto getLogLevelColorSettings() noexcept -> const std::vector<LogLevelColorSettingsEntry>&;
    void saveSettings();

    void connectSettingsChangedSignal(SettingsChangedSignal::slot_type slot);

private:
    SettingsManager();

    static void createYamlFile();
    void loadSettingsFromYamlFile();

    std::vector<LogLevelColorSettingsEntry> m_logLevelColorSettings;
    SettingsChangedSignal m_settingsChangedSignal;
};


} // namespace Model