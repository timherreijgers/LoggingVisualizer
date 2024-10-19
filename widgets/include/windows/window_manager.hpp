/*
 * Copyright © 2024 Tim Herreijgers
 * Licensed using the MIT license
 */

#pragma once

#include "main_window.hpp"
#include "settings_window.hpp"

namespace Windows
{

class WindowManager
{
public:
    [[nodiscard]] auto getMainWindow() noexcept -> MainWindow&;
    [[nodiscard]] auto getSettingsWindow() noexcept -> SettingsWindow&;

private:
    MainWindow m_mainWindow;
    SettingsWindow m_settingsWindow;
};

} // namespace Windows