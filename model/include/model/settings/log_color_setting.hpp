/*
 * Copyright © 2025 Tim Herreijgers
 * Licensed using the MIT license
 */

#pragma once

#include "settings_node.hpp"
#include "settings_object.hpp"
#include "types/color.hpp"

#include <string>
#include <vector>

namespace Model
{

struct LogColorSettingEntryData
{
    int logLevelIndex;
    std::string logLevel;
    Types::Color foregroundColor;
    Types::Color backgroundColor;

    constexpr auto operator==(const LogColorSettingEntryData& rhs) const -> bool = default;
};

class LogColorSettingEntry
{
public:
    LogColorSettingEntry(SettingsObject<LogColorSettingEntryData>& node, LogColorSettingEntryData data);

    [[nodiscard]] auto getLogLevelIndex() const noexcept -> int;
    [[nodiscard]] auto getLogLevel() const noexcept -> std::string_view;
    [[nodiscard]] auto getForegroundColor() const noexcept -> Types::Color;
    [[nodiscard]] auto getBackgroundColor() const noexcept -> Types::Color;

    void setLogLevelIndex(int logLevelIndex);
    void setLogLevel(std::string_view logLevel);
    void setForegroundColor(Types::Color foregroundColor);
    void setBackgroundColor(Types::Color backgroundColor);

    auto operator==(const LogColorSettingEntry&) const -> bool;

private:
    SettingsObject<LogColorSettingEntryData>& m_settingsNode;
    LogColorSettingEntryData m_data;
};

class LogColorSetting
{
public:
    explicit LogColorSetting(SettingsNode& node);

    void addLogColorSettings(std::string_view logLevel, Types::Color foregroundColor, Types::Color backgroundColor) noexcept;
    [[nodiscard]] auto getLogColorSettingsEntries() const noexcept -> const std::vector<LogColorSettingEntry>&;
    [[nodiscard]] auto getLogColorSettingsEntries() noexcept -> std::vector<LogColorSettingEntry>&;
    [[nodiscard]] auto getLogColorSetting(std::string_view debugLevel) const -> const LogColorSettingEntry&;
    [[nodiscard]] auto getLogColorSetting(std::string_view debugLevel) -> LogColorSettingEntry&;

private:
    SettingsNode& m_settingsNode;
    std::vector<LogColorSettingEntry> m_entries;
};

} // namespace Model