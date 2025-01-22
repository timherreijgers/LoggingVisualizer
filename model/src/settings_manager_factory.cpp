/*
 * Copyright © 2024-2025 Tim Herreijgers
 * Licensed using the MIT license
 */

#include "model/settings_manager_factory.hpp"

#include "settings_manager.hpp"

namespace Model
{

std::unique_ptr<ISettingsManager> SettingsManagerFactory::m_settingsManager;

auto SettingsManagerFactory::createSettingsManager() noexcept -> ISettingsManager&
{
    if (!m_settingsManager)
    {
        m_settingsManager = std::make_unique<SettingsManager>();
    }

    return *m_settingsManager;
}
} // namespace Model