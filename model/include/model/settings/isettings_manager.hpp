/*
 * Copyright © 2025 Tim Herreijgers
 * Licensed using the MIT license
 */

#pragma once

#include "model/settings/settings_group.hpp"
#include "model/signal.hpp"

#include <vector>

namespace Model
{

enum class SettingsGroupId
{
    LOG_LEVELS
};

class ISettingsManager
{
public:
    ISettingsManager() = default;
    virtual ~ISettingsManager() = default;
    ISettingsManager(const ISettingsManager& other) = delete;
    ISettingsManager& operator=(const ISettingsManager& other) = delete;
    ISettingsManager(ISettingsManager&& other) = delete;
    ISettingsManager& operator=(ISettingsManager&& other) = delete;

    [[nodiscard]] virtual auto getSettingGroups() const noexcept -> const std::vector<SettingsGroup>& = 0;

    [[nodiscard]] virtual auto getSettingGroup(SettingsGroupId id) const noexcept -> const SettingsGroup& = 0;
    [[nodiscard]] virtual auto getSettingGroup(SettingsGroupId id) noexcept -> SettingsGroup& = 0;

    virtual void saveSettings() noexcept = 0;

    using SettingsModifiedSignal = Signals::signal<void(bool)>;
    [[nodiscard]] virtual auto connectSettingsModified(SettingsModifiedSignal::slot_type slot) -> Signals::scoped_connection = 0;
    [[nodiscard]] virtual auto isModified() const noexcept -> bool = 0;
    virtual void resetModified() noexcept = 0;
};

} // namespace Model::NewSettings
