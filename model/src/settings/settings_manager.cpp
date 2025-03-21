/*
 * Copyright © 2025 Tim Herreijgers
 * Licensed using the MIT license
 */

#include "settings_manager.hpp"

namespace Model::NewSettings
{

SettingsManager::SettingsManager()
{
    auto& logLevelsGroup = m_groups.emplace_back("Log Levels");
    LogColorSetting logColorSetting{};
    logColorSetting.addLogColorSettings("TRACE", "#000000", "#FFFFFF");
    logColorSetting.addLogColorSettings("DEBUG", "#000000", "#FFFFFF");
    logColorSetting.addLogColorSettings("INFO", "#000000", "#FFFFFF");
    logColorSetting.addLogColorSettings("WARNING", "#000000", "#FFFFFF");
    logColorSetting.addLogColorSettings("ERROR", "#000000", "#FFFFFF");
    logColorSetting.addLogColorSettings("CRITICAL", "#000000", "#FFFFFF");
    logLevelsGroup.addSetting(std::move(logColorSetting));
}


auto SettingsManager::getSettingGroups() const noexcept -> const std::vector<SettingsGroup>&
{
    return m_groups;
}

auto SettingsManager::getSettingGroup(SettingsGroupId id) const noexcept -> const SettingsGroup&
{
    return m_groups[std::to_underlying(id)];
}

auto SettingsManager::getSettingGroup(SettingsGroupId id) noexcept -> SettingsGroup&
{
    return m_groups[std::to_underlying(id)];
}


} // namespace Model::NewSettings