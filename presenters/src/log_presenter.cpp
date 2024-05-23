/*
 * Copyright © 2024 Tim Herreijgers
 * Licensed using the MIT license
 */

#include "presenters/log_presenter.h"

#include <iostream>

namespace Presenters
{

LogPresenter::LogPresenter(Widgets::LogWidget & view, Model::LogDataContext& model)
        : m_view(view), m_model(model)
{
    model.subscribeToLogEntiesChanged([&](const std::vector<Types::LogEntry>& logEntries) {
        view.setLogMessages(logEntries);
    });
}

} // namespace Presenters