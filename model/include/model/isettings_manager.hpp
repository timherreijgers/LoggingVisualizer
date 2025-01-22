/*
 * Copyright © 2025 Tim Herreijgers
 * Licensed using the MIT license
 */

#pragma once

#include "log_level_color_settings_entry.hpp"
#include "model/signal.hpp"
#include "types/color.hpp"

namespace Model
{

class ISettingsManager
{
public:
    ISettingsManager() = default;
    virtual ~ISettingsManager() = default;
    ISettingsManager(const ISettingsManager&) = delete;
    ISettingsManager& operator=(const ISettingsManager&) = delete;
    ISettingsManager(ISettingsManager&&) = delete;
    ISettingsManager& operator=(ISettingsManager&&) = delete;

    using SettingsChangedSignal = Signals::signal<void()>;

    virtual void setLogLevelColorSettings(std::string level, Types::Color textColor, Types::Color backgroundColor) = 0;
    [[nodiscard]] virtual auto getLogLevelColorSettings() noexcept -> const std::vector<LogLevelColorSettingsEntry>& = 0;
    virtual void saveSettings() = 0;

    // TODO: Add nodiscard
    virtual auto connectSettingsChangedSignal(SettingsChangedSignal::slot_type slot) -> Signals::connection = 0;
};

} // namespace Model