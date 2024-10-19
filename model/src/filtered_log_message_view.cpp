/*
 * Copyright © 2024 Tim Herreijgers
 * Licensed using the MIT license
 */

#include "filtered_log_message_view.hpp"

#include <stdexcept>

namespace Model
{

auto FilteredLogMessageView::get(size_t index) const -> const Types::LogEntry&
{
    if (!m_sourceMessages)
    {
        throw std::runtime_error("FilteredLogMessageView::get: Source message is empty");
    }

    return (*m_sourceMessages)[m_logIndices[index]];
}

auto FilteredLogMessageView::operator[](size_t index) const -> const Types::LogEntry&
{
    return get(index);
}

auto FilteredLogMessageView::size() const noexcept -> size_t
{
    return m_logIndices.size();
}

auto FilteredLogMessageView::empty() const noexcept -> bool
{
    return m_logIndices.empty();
}

void FilteredLogMessageView::setSource(const std::vector<Types::LogEntry> * sourceMessages)
{
    m_sourceMessages = sourceMessages;
}

void FilteredLogMessageView::addIndex(size_t index)
{
    m_logIndices.push_back(index);
}

void FilteredLogMessageView::clearIndices()
{
    m_logIndices.clear();
}

} // namespace Model