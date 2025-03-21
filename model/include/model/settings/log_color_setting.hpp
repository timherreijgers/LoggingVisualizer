/*
 * Copyright © 2025 Tim Herreijgers
 * Licensed using the MIT license
 */

#pragma once

#include "model/signal.hpp"

#include <string>
#include <vector>

namespace Model
{

class LogColorSettingEntry
{
public:
    using LogColorSettingEntryChanged = Signals::signal<void(const LogColorSettingEntry&)>;

    LogColorSettingEntry(int logLevelIndex, std::string_view logLevel, std::string_view foregroundColor, std::string_view backgroundColor);

    [[nodiscard]] auto connectEntryChanged(const LogColorSettingEntryChanged::slot_type& slot) noexcept -> Signals::scoped_connection;

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
    int m_logLevelIndex;
    std::string m_logLevel;
    std::string m_foregroundColor;
    std::string m_backgroundColor;

    LogColorSettingEntryChanged m_EntryChangedSignal;
};

class LogColorSetting
{
public:
    LogColorSetting() = default;

    void addLogColorSettings(std::string_view logLevel, std::string_view foregroundColor, std::string_view backgroundColor) noexcept;
    [[nodiscard]] auto getLogColorSettingsEntries() const noexcept -> const std::vector<LogColorSettingEntry>&;
    [[nodiscard]] auto getLogColorSettingsEntries() noexcept -> std::vector<LogColorSettingEntry>&;
    [[nodiscard]] auto getLogColorSetting(std::string_view debugLevel) const -> const LogColorSettingEntry&;
    [[nodiscard]] auto getLogColorSetting(std::string_view debugLevel) -> LogColorSettingEntry&;

private:
    std::vector<LogColorSettingEntry> m_entries;
    std::vector<Signals::scoped_connection> m_connections;

    void entryUpdated(const LogColorSettingEntry& entry);
};

} // namespace Model