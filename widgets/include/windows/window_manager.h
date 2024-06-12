/*
 * Copyright © 2024 Tim Herreijgers
 * Licensed using the MIT license
 */

#pragma once

#include "main_window.h"
#include "settings_window.h"

namespace Windows
{

class WindowManager
{
public:
    [[nodiscard]] static auto createMainWindow() noexcept -> MainWindow &;
    [[nodiscard]] static auto createSettingsWindow() noexcept -> SettingsWindow &;
};

} // namespace Windows