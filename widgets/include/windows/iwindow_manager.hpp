/*
 * Copyright © 2024 Tim Herreijgers
 * Licensed using the MIT license
 */

#pragma once

#include "main_window.hpp"
#include "settings_window.hpp"

namespace Windows
{

class IWindowManager
{
public:
    virtual ~IWindowManager() = default;

    [[nodiscard]] virtual auto getMainWindow() noexcept -> MainWindow& = 0;
    [[nodiscard]] virtual auto getSettingsWindow() noexcept -> SettingsWindow& = 0;
};

} // namespace Windows
