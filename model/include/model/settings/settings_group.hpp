/*
 * Copyright © 2025 Tim Herreijgers
 * Licensed using the MIT license
 */

#pragma once

#include "log_color_setting.hpp"

#include <string>
#include <variant>
#include <vector>

namespace Model
{

using SettingsVariant = std::variant<LogColorSetting>;

class SettingsGroup
{
public:
    explicit SettingsGroup(const std::string& name);

    void addSetting(SettingsVariant settings);

    [[nodiscard]] auto getName() const noexcept -> std::string_view;
    [[nodiscard]] auto getSettings() const noexcept -> const std::vector<SettingsVariant>&;
    [[nodiscard]] auto getSettings() noexcept -> std::vector<SettingsVariant>&;

private:
    std::string m_name;
    std::vector<SettingsVariant> m_settings;
};

} // namespace Model