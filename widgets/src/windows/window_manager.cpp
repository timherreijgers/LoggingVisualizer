/*
 * Copyright © 2024-2025 Tim Herreijgers
 * Licensed using the MIT license
 */

#include "windows/window_manager.hpp"

#include "settings_window.hpp"

auto Windows::WindowManager::getMainWindow() noexcept -> MainWindow&
{
    return m_mainWindow;
}

auto Windows::WindowManager::getSettingsWindow() noexcept -> ISettingsWindow&
{
    return m_settingsWindow;
}