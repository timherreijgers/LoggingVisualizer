/*
 * Copyright © 2024 Tim Herreijgers
 * Licensed using the MIT license
 */

#include "log_message_filter.h"

#include <utility>

namespace Model
{

void LogMessageFilter::setFilter(const std::string& filter) noexcept
{
    m_filter = filter;
    filterMessages();
    m_logMessageChangedSignal();
}

void LogMessageFilter::setFilterEnabled(bool enabled) noexcept
{
    m_filterEnabled = enabled;
    filterMessages();
    m_logMessageChangedSignal();
}

auto LogMessageFilter::filterEnabled() const noexcept -> bool
{
    return m_filterEnabled;
}

void LogMessageFilter::setInputMessages(const std::vector<Types::LogEntry>& messages)
{
    m_inputMessages = messages;
    m_filteredMessages.setSource(&m_inputMessages);
    filterMessages();
    m_logMessageChangedSignal();
}

auto LogMessageFilter::connectLogMessagesChanged(logMessageChangedSignal::slot_type slot) noexcept -> is::signals::connection
{
    return m_logMessageChangedSignal.connect(std::move(slot));
}

auto LogMessageFilter::getLogMessages() const noexcept -> const FilteredLogMessageView&
{
    return m_filteredMessages;
}

void LogMessageFilter::filterMessages() noexcept
{
    m_filteredMessages.clearIndices();

    if (!m_filterEnabled)
    {
        for (size_t i = 0; i < m_inputMessages.size(); i++)
        {
            m_filteredMessages.addIndex(i);
        }
    }

    for (size_t i = 0; i < m_inputMessages.size(); i++)
    {
        if (m_inputMessages[i].message.contains(m_filter))
        {
            m_filteredMessages.addIndex(i);
        }
    }
}

} // namespace Model