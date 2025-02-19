/*
 * Copyright © 2024-2025 Tim Herreijgers
 * Licensed using the MIT license
 */

#include "windows/window_manager.hpp"

#include "settings_window.hpp"

Windows::WindowManager::WindowManager() :
    m_settingsWindow(std::make_unique<SettingsWindow>())
{
}


auto Windows::WindowManager::getMainWindow() noexcept -> MainWindow&
{
    return m_mainWindow;
}

auto Windows::WindowManager::getSettingsWindow() noexcept -> ISettingsWindow&
{
    return *m_settingsWindow;
}