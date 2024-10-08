/*
 * Copyright © 2024 Tim Herreijgers
 * Licensed using the MIT license
 */

#include "presenters/base_presenter.h"

namespace Presenters
{

BasePresenter::BasePresenter(Windows::WindowManager& windowManager) :
    m_windowManager(windowManager)
{
}

auto BasePresenter::getWindowManager() const noexcept -> Windows::WindowManager&
{
    return m_windowManager;
}

} // namespace Presenters