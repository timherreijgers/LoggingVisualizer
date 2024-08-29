/*
 * Copyright © 2024 Tim Herreijgers
 * Licensed using the MIT license
 */

#include "presenters/toolbar_presenter.h"

namespace Presenters
{

ToolbarPresenter::ToolbarPresenter(Widgets::Toolbar & view, Model::ILogDataContext &model)
    : m_view(view), m_model(model)
{
}

} // namespace Presenters