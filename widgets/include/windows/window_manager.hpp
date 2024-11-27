/*
 * Copyright © 2024 Tim Herreijgers
 * Licensed using the MIT license
 */

#pragma once

#include "iwindow_manager.hpp"
#include "main_window.hpp"
#include "settings_window.hpp"

namespace Windows
{

class WindowManager : public IWindowManager
{
public:
    ~WindowManager() override = default;

    [[nodiscard]] auto getMainWindow() noexcept -> MainWindow& override;
    [[nodiscard]] auto getSettingsWindow() noexcept -> SettingsWindow& override;

private:
    MainWindow m_mainWindow;
    SettingsWindow m_settingsWindow;
};

} // namespace Windows