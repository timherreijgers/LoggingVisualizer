/*
 * Copyright © 2024 Tim Herreijgers
 * Licensed using the MIT license
 */

#include "presenters/base_presenter.hpp"

namespace Presenters
{

BasePresenter::BasePresenter(Windows::IWindowManager& windowManager) :
    m_windowManager(windowManager)
{
}

auto BasePresenter::getWindowManager() const noexcept -> Windows::IWindowManager&
{
    return m_windowManager;
}

} // namespace Presenters