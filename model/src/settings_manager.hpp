/*
 * Copyright © 2024-2025 Tim Herreijgers
 * Licensed using the MIT license
 */

#pragma once

#include "model/isettings_manager.hpp"
#include "model/log_level_color_settings_entry.hpp"
#include "model/signal.hpp"

#include <vector>

namespace Model
{

class SettingsManager : public ISettingsManager
{
public:
    SettingsManager();

    SettingsManager(SettingsManager&) = delete;
    SettingsManager(SettingsManager&&) = delete;
    SettingsManager operator=(SettingsManager&) = delete;
    SettingsManager& operator=(SettingsManager&&) = delete;

    void setLogLevelColorSettings(std::string level, Types::Color textColor, Types::Color backgroundColor) override;
    [[nodiscard]] auto getLogLevelColorSettings() noexcept -> const std::vector<LogLevelColorSettingsEntry>& override;
    void saveSettings() override;

    // TODO: Add nodiscard
    auto connectSettingsChangedSignal(SettingsChangedSignal::slot_type slot) -> Signals::connection override;

private:
    static void createYamlFile();
    void loadSettingsFromYamlFile();

    std::vector<LogLevelColorSettingsEntry> m_logLevelColorSettings;
    SettingsChangedSignal m_settingsChangedSignal;
};


} // namespace Model