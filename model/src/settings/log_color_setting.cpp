/*
 * Copyright © 2025 Tim Herreijgers
 * Licensed using the MIT license
 */

#include "model/settings/log_color_setting.hpp"

#include <functional>

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

void LogColorSettingEntry::setDebugLevelIndex(int logLevelIndex)
{
    m_logLevelIndex = logLevelIndex;
    m_EntryChangedSignal(*this);
}

void LogColorSettingEntry::setLogLevel(const std::string& logLevel)
{
    m_logLevel = logLevel;
    m_EntryChangedSignal(*this);
}

void LogColorSettingEntry::setForegroundColor(const std::string& foregroundColor)
{
    m_foregroundColor = foregroundColor;
    m_EntryChangedSignal(*this);
}

void LogColorSettingEntry::setBackgroundColor(const std::string& backgroundColor)
{
    m_backgroundColor = backgroundColor;
    m_EntryChangedSignal(*this);
}

void LogColorSetting::addLogColorSettings(std::string_view logLevel, std::string_view foregroundColor, std::string_view backgroundColor) noexcept
{
    auto& entry = m_entries.emplace_back(static_cast<int>(m_entries.size()), logLevel, foregroundColor, backgroundColor);
    m_connections.emplace_back(entry.connectEntryChanged([this](const LogColorSettingEntry& entry) { entryUpdated(entry); }));
}

void LogColorSetting::entryUpdated(const LogColorSettingEntry& /*entry*/)
{
}

} // namespace Model