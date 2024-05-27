/*
 * Copyright © 2024 Tim Herreijgers
 * Licensed using the MIT license
 */

#include "windows/window_manager.h"

auto Windows::WindowManager::createMainWindow() noexcept -> MainWindow &
{
    static MainWindow mainWindow;

    return mainWindow;
}

auto Windows::WindowManager::createSettingsWindow() noexcept -> SettingsWindow &
{
    static SettingsWindow settingsWindow;
    return settingsWindow;
}