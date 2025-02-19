/*
 * Copyright © 2024-2025 Tim Herreijgers
 * Licensed using the MIT license
 */

#pragma once

#include "isettings_window.hpp"
#include "main_window.hpp"

namespace Windows
{

class IWindowManager
{
public:
    virtual ~IWindowManager() = default;

    [[nodiscard]] virtual auto getMainWindow() noexcept -> MainWindow& = 0;
    [[nodiscard]] virtual auto getSettingsWindow() noexcept -> ISettingsWindow& = 0;
};

} // namespace Windows
