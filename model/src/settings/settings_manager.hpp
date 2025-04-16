/*
 * Copyright © 2025 Tim Herreijgers
 * Licensed using the MIT license
 */

#pragma once

#include "model/settings/settings_group.hpp"
#include "model/settings/settings_tree.hpp"
#include "model/signal.hpp"

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

    using SettingsModifiedSignal = Signals::signal<void(bool)>;
    [[nodiscard]] auto connectSettingsModified(SettingsModifiedSignal::slot_type slot) -> Signals::scoped_connection;
    [[nodiscard]] auto isModified() const noexcept -> bool;

private:
    std::vector<SettingsGroup> m_groups;
    SettingsModifiedSignal m_settingsModified;
    SettingsTree m_settingsTree;
};

} // namespace Model::NewSettings