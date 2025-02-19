/*
 * Copyright © 2024-2025 Tim Herreijgers
 * Licensed using the MIT license
 */

#pragma once

#include "windows/iwindow_manager.hpp"
#include "windows/main_window.hpp"
#include "windows/settings_window.hpp"

namespace Windows
{

class WindowManager : public IWindowManager
{
public:
    WindowManager() = default;
    ~WindowManager() override = default;

    [[nodiscard]] auto getMainWindow() noexcept -> MainWindow& override;
    [[nodiscard]] auto getSettingsWindow() noexcept -> ISettingsWindow& override;

private:
    MainWindow m_mainWindow;
    SettingsWindow m_settingsWindow;
};

} // namespace Windows