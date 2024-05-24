/*
 * Copyright © 2024 Tim Herreijgers
 * Licensed using the MIT license
 */

#include "presenters/log_presenter.h"

#include <iostream>

namespace Presenters
{

LogPresenter::LogPresenter(Widgets::LogWidget & view, Model::LogDataContext & model) :
    m_view(view), m_model(model)
{
    m_view.setLogMessages({});

    model.subscribeToLogEntiesChanged([this](const std::vector<Types::LogEntry>& data){logMessagesUpdated(data);});
}

void LogPresenter::logMessagesUpdated(const std::vector<Types::LogEntry> & logEntries) noexcept
{
    m_view.setLogMessages(logEntries);
}

} // namespace Presenters