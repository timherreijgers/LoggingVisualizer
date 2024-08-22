/*
 * Copyright © 2024 Tim Herreijgers
 * Licensed using the MIT license
 */

#include <utility>

#include "log_message_filter.h"

namespace Model
{

void LogMessageFilter::setFilter(const std::string &) noexcept
{
}

void LogMessageFilter::setFilterEnabled(bool) noexcept
{
}

void LogMessageFilter::setInputMessages(const std::vector<Types::LogEntry>& messages)
{
    m_observableVector.setValue(messages);
}

void LogMessageFilter::subscribeToLogEntriesChanged(LogEntriesChangedListener listener) noexcept
{
    m_observableVector.subscribe(std::move(listener));
}

} // namespace Model