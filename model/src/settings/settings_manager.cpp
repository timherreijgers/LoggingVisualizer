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

    std::unique_ptr<SettingsNode> logColorSettingNode = std::make_unique<SettingsNode>(&m_settingsTree);
    LogColorSetting logColorSetting{*logColorSettingNode};
    m_settingsTree.addChild(std::move(logColorSettingNode));

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

auto SettingsManager::connectSettingsModified(SettingsModifiedSignal::slot_type slot) -> Signals::scoped_connection
{
    return m_settingsModified.connect(std::move(slot));
}

auto SettingsManager::isModified() const noexcept -> bool
{
    return m_settingsTree.isModified();
}


} // namespace Model::NewSettings