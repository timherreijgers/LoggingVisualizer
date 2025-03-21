/*
 * Copyright © 2025 Tim Herreijgers
 * Licensed using the MIT license
 */

#include "model/settings/log_color_setting.hpp"

#include "exceptions/log_level_not_found_exception.hpp"

#include <ranges>

namespace Model
{

LogColorSettingEntry::LogColorSettingEntry(int logLevelIndex, std::string_view logLevel, std::string_view foregroundColor, std::string_view backgroundColor) :
    m_logLevelIndex(logLevelIndex), m_logLevel(logLevel), m_foregroundColor(foregroundColor), m_backgroundColor(backgroundColor)
{
}

auto LogColorSettingEntry::connectEntryChanged(const LogColorSettingEntryChanged::slot_type& slot) noexcept -> Signals::scoped_connection
{
    return Signals::scoped_connection{m_EntryChangedSignal.connect(slot)};
}

auto LogColorSettingEntry::getLogLevelIndex() const noexcept -> int
{
    return m_logLevelIndex;
}

auto LogColorSettingEntry::getLogLevel() const noexcept -> std::string_view
{
    return m_logLevel;
}

auto LogColorSettingEntry::getForegroundColor() const noexcept -> std::string_view
{
    return m_foregroundColor;
}

auto LogColorSettingEntry::getBackgroundColor() const noexcept -> std::string_view
{
    return m_backgroundColor;
}

void LogColorSettingEntry::setLogLevelIndex(int logLevelIndex)
{
    m_logLevelIndex = logLevelIndex;
    m_EntryChangedSignal(*this);
}

void LogColorSettingEntry::setLogLevel(std::string_view logLevel)
{
    m_logLevel = logLevel;
    m_EntryChangedSignal(*this);
}

void LogColorSettingEntry::setForegroundColor(std::string_view foregroundColor)
{
    m_foregroundColor = foregroundColor;
    m_EntryChangedSignal(*this);
}

void LogColorSettingEntry::setBackgroundColor(std::string_view backgroundColor)
{
    m_backgroundColor = backgroundColor;
    m_EntryChangedSignal(*this);
}

auto LogColorSettingEntry::operator==(const LogColorSettingEntry& other) const -> bool
{
    return other.m_logLevelIndex == m_logLevelIndex &&
           other.m_foregroundColor == m_foregroundColor &&
           other.m_backgroundColor == m_backgroundColor &&
           other.m_logLevel == m_logLevel;
}

void LogColorSetting::addLogColorSettings(std::string_view logLevel, std::string_view foregroundColor, std::string_view backgroundColor) noexcept
{
    auto& entry = m_entries.emplace_back(static_cast<int>(m_entries.size()), logLevel, foregroundColor, backgroundColor);
    m_connections.emplace_back(entry.connectEntryChanged([this](const LogColorSettingEntry& e) { entryUpdated(e); }));
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