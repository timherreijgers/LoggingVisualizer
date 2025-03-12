/*
 * Copyright © 2025 Tim Herreijgers
 * Licensed using the MIT license
 */

#pragma once

#include "model/settings/settings_group.hpp"

#include <vector>

namespace Model::NewSettings
{

enum class SettingsGroupId
{
    LOG_LEVELS
};

class SettingsManager
{
public:
    explicit SettingsManager();

    [[nodiscard]] auto getSettingGroups() const noexcept -> const std::vector<SettingsGroup>&;

    [[nodiscard]] auto getSettingGroup(SettingsGroupId id) const noexcept -> const SettingsGroup&;
    [[nodiscard]] auto getSettingGroup(SettingsGroupId id) noexcept -> SettingsGroup&;

private:
    std::vector<SettingsGroup> m_groups;
};

} // namespace Model::NewSettings