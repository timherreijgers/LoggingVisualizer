/*
 * Copyright © 2025 Tim Herreijgers
 * Licensed using the MIT license
 */

#pragma once

#include "model/settings/isettings_manager.hpp"
#include "model/settings/settings_group.hpp"
#include "model/settings/settings_tree.hpp"

#include <yaml-cpp/yaml.h>

#include <functional>
#include <map>

namespace Model::NewSettings
{

class SettingsManager : public ISettingsManager
{
public:
    explicit SettingsManager();

    [[nodiscard]] auto getSettingGroups() const noexcept -> const std::vector<SettingsGroup>& override;

    [[nodiscard]] auto getSettingGroup(SettingsGroupId id) const noexcept -> const SettingsGroup& override;
    [[nodiscard]] auto getSettingGroup(SettingsGroupId id) noexcept -> SettingsGroup& override;

    void saveSettings() noexcept override;

    [[nodiscard]] auto connectSettingsModified(SettingsModifiedSignal::slot_type slot) -> Signals::scoped_connection override;
    [[nodiscard]] auto isModified() const noexcept -> bool override;
    void resetModified() noexcept override;

private:
    std::vector<SettingsGroup> m_groups;
    SettingsTree m_settingsTree;
    std::map<std::string_view, std::function<void(const YAML::Node&)>> m_yamlLoadingGroupFunctions;

    [[nodiscard]] auto createYamlLoadingGroupFunctions() -> std::map<std::string_view, std::function<void(const YAML::Node&)>>;
    void loadSettingsFromYamlFile();

    void loadLogLevelSettingsFromYamlFile(const YAML::Node& node);
};

} // namespace Model::NewSettings