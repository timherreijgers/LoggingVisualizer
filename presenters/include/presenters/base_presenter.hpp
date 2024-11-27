/*
 * Copyright © 2024 Tim Herreijgers
 * Licensed using the MIT license
 */

#pragma once

#include "windows/iwindow_manager.hpp"

namespace Presenters
{

class BasePresenter
{
public:
    explicit BasePresenter(Windows::IWindowManager& windowManager);

protected:
    [[nodiscard]] auto getWindowManager() const noexcept -> Windows::IWindowManager&;

private:
    Windows::IWindowManager& m_windowManager;
};

} // namespace Presenters