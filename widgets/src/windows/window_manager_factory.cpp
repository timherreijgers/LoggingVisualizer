/*
 * Copyright © 2025 Tim Herreijgers
 * Licensed using the MIT license
 */

#include "windows/window_manager_factory.hpp"

#include "window_manager.hpp"

namespace Windows
{

auto WindowManagerFactory::createWindowManager() noexcept -> std::unique_ptr<IWindowManager>
{
    return std::make_unique<WindowManager>();
}


} // namespace Windows