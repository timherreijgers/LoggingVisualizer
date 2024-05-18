/*
 * Copyright © 2024 Tim Herreijgers
 * Licensed using the MIT license
 */

#include "presenters/log_presenter.h"

namespace Presenters
{

LogPresenter::LogPresenter(Widgets::LogWidget & view, Model::LogSource model)
        : m_view(view), m_model(model)
{
    view.setLogMessages(model.getLogEntries());
}

} // namespace Presenters