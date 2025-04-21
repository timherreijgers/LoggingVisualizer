/*
 * Copyright © 2025 Tim Herreijgers
 * Licensed using the MIT license
 */

#include "model/settings/log_color_setting.hpp"

#include "exceptions/log_level_not_found_exception.hpp"
#include "types/color.hpp"

#include <ranges>

namespace Model
{

LogColorSettingEntry::LogColorSettingEntry(SettingsObject<LogColorSettingEntryData>& node, LogColorSettingEntryData data) :
    m_settingsNode(node), m_data(std::move(data))
{
}

auto LogColorSettingEntry::getLogLevelIndex() const noexcept -> int
{
    return m_data.logLevelIndex;
}

auto LogColorSettingEntry::getLogLevel() const noexcept -> std::string_view
{
    return m_data.logLevel;
}

auto LogColorSettingEntry::getForegroundColor() const noexcept -> Types::Color
{
    return m_data.foregroundColor;
}

auto LogColorSettingEntry::getBackgroundColor() const noexcept -> Types::Color
{
    return m_data.backgroundColor;
}

void LogColorSettingEntry::setLogLevelIndex(int logLevelIndex)
{
    m_data.logLevelIndex = logLevelIndex;
    m_settingsNode.setNewValue(m_data);
}

void LogColorSettingEntry::setLogLevel(std::string_view logLevel)
{
    m_data.logLevel = logLevel;
    m_settingsNode.setNewValue(m_data);
}

void LogColorSettingEntry::setForegroundColor(Types::Color foregroundColor)
{
    m_data.foregroundColor = foregroundColor;
    m_settingsNode.setNewValue(m_data);
}

void LogColorSettingEntry::setBackgroundColor(Types::Color backgroundColor)
{
    m_data.backgroundColor = backgroundColor;
    m_settingsNode.setNewValue(m_data);
}

auto LogColorSettingEntry::operator==(const LogColorSettingEntry& other) const -> bool
{
    return other.m_data == m_data;
}

LogColorSetting::LogColorSetting(SettingsNode& node) :
    m_settingsNode(node)
{
}

void LogColorSetting::addLogColorSettings(std::string_view logLevel, Types::Color foregroundColor, Types::Color backgroundColor) noexcept
{
    LogColorSettingEntryData data{static_cast<int>(m_entries.size()),
                                  std::string{logLevel}, foregroundColor, backgroundColor};

    std::unique_ptr<SettingsObject<LogColorSettingEntryData>> node = std::make_unique<SettingsObject<LogColorSettingEntryData>>(&m_settingsNode, data);
    m_entries.emplace_back(*node, data);
    m_settingsNode.addChild(std::move(node));
}

auto LogColorSetting::getLogColorSettingsEntries() const noexcept -> const std::vector<LogColorSettingEntry>&
{
    return m_entries;
}

auto LogColorSetting::getLogColorSettingsEntries() noexcept -> std::vector<LogColorSettingEntry>&
{
    return m_entries;
}

auto LogColorSetting::getLogColorSetting(std::string_view debugLevel) const -> const LogColorSettingEntry&
{
    const auto& result = std::ranges::find_if(m_entries, [&debugLevel](const LogColorSettingEntry& entry) { return entry.getLogLevel() == debugLevel; });

    if (result == m_entries.end())
        throw Exceptions::LogLevelNotFoundException(debugLevel);

    return *result;
}

auto LogColorSetting::getLogColorSetting(std::string_view debugLevel) -> LogColorSettingEntry&
{
    const auto& result = std::ranges::find_if(m_entries, [&debugLevel](const LogColorSettingEntry& entry) { return entry.getLogLevel() == debugLevel; });

    if (result == m_entries.end())
        throw Exceptions::LogLevelNotFoundException(debugLevel);

    return *result;
}

void LogColorSetting::entryUpdated(const LogColorSettingEntry& /*entry*/)
{
}

} // namespace Model