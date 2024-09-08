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
    m_outputMessages = filterMessages();
    m_logMessageChangedSignal();
}

void LogMessageFilter::setFilterEnabled(bool enabled) noexcept
{
    m_filterEnabled = enabled;
    m_outputMessages = filterMessages();
    m_logMessageChangedSignal();
}

auto LogMessageFilter::filterEnabled() const noexcept -> bool
{
    return m_filterEnabled;
}

void LogMessageFilter::setInputMessages(const std::vector<Types::LogEntry>& messages)
{
    m_inputMessages = messages;
    m_outputMessages = filterMessages();
    m_logMessageChangedSignal();
}

auto LogMessageFilter::connectLogMessagesChanged(logMessageChangedSignal::slot_type slot) noexcept -> is::signals::connection
{
    return m_logMessageChangedSignal.connect(std::move(slot));
}

auto LogMessageFilter::getLogMessages() const noexcept -> const std::vector<Types::LogEntry> &
{
    return m_outputMessages;
}

auto LogMessageFilter::filterMessages() noexcept -> std::vector<Types::LogEntry>
{
    if (!m_filterEnabled)
    {
        return m_inputMessages;
    }

    std::vector<Types::LogEntry> filteredMessages;

    for (const auto& entry : m_inputMessages)
    {
        if (entry.message.contains(m_filter))
            filteredMessages.push_back(entry);
    }

    return filteredMessages;
}

} // namespace Model