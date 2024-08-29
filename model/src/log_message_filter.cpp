/*
 * Copyright © 2024 Tim Herreijgers
 * Licensed using the MIT license
 */

#include <utility>

#include "log_message_filter.h"

namespace Model
{

void LogMessageFilter::setFilter(const std::string & filter) noexcept
{
    m_filter = filter;
    m_observableVector.setValue(filterMessages());
}

void LogMessageFilter::setFilterEnabled(bool) noexcept
{
}

void LogMessageFilter::setInputMessages(const std::vector<Types::LogEntry>& messages)
{
    m_inputMessages = messages;
    m_observableVector.setValue(filterMessages());
}

void LogMessageFilter::subscribeToLogEntriesChanged(LogEntriesChangedListener listener) noexcept
{
    m_observableVector.subscribe(std::move(listener));
}

auto LogMessageFilter::filterMessages() -> std::vector<Types::LogEntry>
{
    std::vector<Types::LogEntry> filteredMessages;

    for (const auto& entry : m_inputMessages)
    {
        if (entry.message.contains(m_filter))
            filteredMessages.push_back(entry);
    }

    return filteredMessages;
}

} // namespace Model