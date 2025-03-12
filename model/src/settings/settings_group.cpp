/*
 * Copyright © 2025 Tim Herreijgers
 * Licensed using the MIT license
 */

#include "model/settings/settings_group.hpp"

namespace Model
{

SettingsGroup::SettingsGroup(const std::string& name) :
    m_name(name)
{
}

void SettingsGroup::addSetting(SettingsVariant settings)
{
    m_settings.emplace_back(std::move(settings));
}

auto SettingsGroup::getName() const noexcept -> std::string_view
{
    return m_name;
}

auto SettingsGroup::getSettings() const noexcept -> const std::vector<SettingsVariant>&
{
    return m_settings;
}

auto SettingsGroup::getSettings() noexcept -> std::vector<SettingsVariant>&
{
    return m_settings;
}

} // namespace Model