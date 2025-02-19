/*
 * Copyright © 2024-2025 Tim Herreijgers
 * Licensed using the MIT license
 */

#pragma once

#include "isettings_window.hpp"
#include "iwindow_manager.hpp"
#include "main_window.hpp"

namespace Windows
{

class WindowManager : public IWindowManager
{
public:
    WindowManager();
    ~WindowManager() override = default;

    [[nodiscard]] auto getMainWindow() noexcept -> MainWindow& override;
    [[nodiscard]] auto getSettingsWindow() noexcept -> ISettingsWindow& override;

private:
    MainWindow m_mainWindow;
    std::unique_ptr<ISettingsWindow> m_settingsWindow;
};

} // namespace Windows