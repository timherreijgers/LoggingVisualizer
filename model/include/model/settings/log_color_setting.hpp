/*
 * Copyright © 2025 Tim Herreijgers
 * Licensed using the MIT license
 */

#pragma once

#include "settings_node.hpp"
#include "settings_object.hpp"

#include <string>
#include <vector>

namespace Model
{

struct LogColorSettingEntryData
{
    int logLevelIndex;
    std::string logLevel;
    std::string foregroundColor;
    std::string backgroundColor;

    constexpr auto operator==(const LogColorSettingEntryData& rhs) const -> bool = default;
};

class LogColorSettingEntry
{
public:
    LogColorSettingEntry(SettingsObject<LogColorSettingEntryData>& node, LogColorSettingEntryData data);

    [[nodiscard]] auto getLogLevelIndex() const noexcept -> int;
    [[nodiscard]] auto getLogLevel() const noexcept -> std::string_view;
    [[nodiscard]] auto getForegroundColor() const noexcept -> std::string_view;
    [[nodiscard]] auto getBackgroundColor() const noexcept -> std::string_view;

    void setLogLevelIndex(int logLevelIndex);
    void setLogLevel(std::string_view logLevel);
    void setForegroundColor(std::string_view foregroundColor);
    void setBackgroundColor(std::string_view backgroundColor);

    auto operator==(const LogColorSettingEntry&) const -> bool;

private:
    SettingsObject<LogColorSettingEntryData>& m_settingsNode;
    LogColorSettingEntryData m_data;
};

class LogColorSetting
{
public:
    explicit LogColorSetting(SettingsNode& node);

    void addLogColorSettings(std::string_view logLevel, std::string_view foregroundColor, std::string_view backgroundColor) noexcept;
    [[nodiscard]] auto getLogColorSettingsEntries() const noexcept -> const std::vector<LogColorSettingEntry>&;
    [[nodiscard]] auto getLogColorSettingsEntries() noexcept -> std::vector<LogColorSettingEntry>&;
    [[nodiscard]] auto getLogColorSetting(std::string_view debugLevel) const -> const LogColorSettingEntry&;
    [[nodiscard]] auto getLogColorSetting(std::string_view debugLevel) -> LogColorSettingEntry&;

private:
    SettingsNode& m_settingsNode;
    std::vector<LogColorSettingEntry> m_entries;

    void entryUpdated(const LogColorSettingEntry& entry);
};

} // namespace Model