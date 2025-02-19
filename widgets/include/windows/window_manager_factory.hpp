/*
 * Copyright © 2025 Tim Herreijgers
 * Licensed using the MIT license
 */

#pragma once

#include "iwindow_manager.hpp"

#include <memory>

namespace Windows
{

class WindowManagerFactory
{
public:
    WindowManagerFactory() = delete;
    [[nodiscard]] static auto createWindowManager() noexcept -> std::unique_ptr<IWindowManager>;
};

} // namespace Windows