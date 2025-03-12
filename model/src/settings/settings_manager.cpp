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
    logLevelsGroup.addSetting(LogColorSetting{});
}


auto SettingsManager::getSettingGroups() const noexcept -> const std::vector<SettingsGroup>&
{
    return m_groups;
}

auto SettingsManager::getSettingGroup(SettingsGroupId id) const noexcept -> const SettingsGroup&
{
    return m_groups[static_cast<int>(id)];
}

auto SettingsManager::getSettingGroup(SettingsGroupId id) noexcept -> SettingsGroup&
{
    return m_groups[static_cast<int>(id)];
}


} // namespace Model::NewSettings