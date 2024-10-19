/*
 * Copyright © 2024 Tim Herreijgers
 * Licensed using the MIT license
 */

#include "windows/window_manager.hpp"

auto Windows::WindowManager::getMainWindow() noexcept -> MainWindow&
{
    return m_mainWindow;
}

auto Windows::WindowManager::getSettingsWindow() noexcept -> SettingsWindow&
{
    return m_settingsWindow;
}