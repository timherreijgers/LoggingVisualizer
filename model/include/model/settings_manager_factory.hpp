/*
 * Copyright © 2025 Tim Herreijgers
 * Licensed using the MIT license
 */

#pragma once

#include "isettings_manager.hpp"

#include <memory>

namespace Model
{

class SettingsManagerFactory
{
public:
    [[nodiscard]] auto static createSettingsManager() noexcept -> ISettingsManager&;

private:
    static std::unique_ptr<ISettingsManager> m_settingsManager;
};

} // namespace Model