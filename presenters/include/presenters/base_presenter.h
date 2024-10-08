/*
 * Copyright © 2024 Tim Herreijgers
 * Licensed using the MIT license
 */

#pragma once

#include "windows/window_manager.h"

namespace Presenters
{

class BasePresenter
{
public:
    explicit BasePresenter(Windows::WindowManager& windowManager);

protected:
    [[nodiscard]] auto getWindowManager() const noexcept -> Windows::WindowManager&;

private:
    Windows::WindowManager& m_windowManager;
};

} // namespace Presenters