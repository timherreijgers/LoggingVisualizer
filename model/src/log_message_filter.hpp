/*
 * Copyright © 2024 Tim Herreijgers
 * Licensed using the MIT license
 */

#pragma once

#include "filtered_log_message_view.hpp"
#include "model/ilog_message_filter.hpp"
#include "types/log_entry.hpp"

#include "model/signal.hpp"

#include <vector>

namespace Model
{

using logMessageChangedSignal = Signals::signal<void()>;

class LogMessageFilter : public ILogMessageFilter
{
public:
    explicit LogMessageFilter() = default;

    void setFilter(const std::string& filter) noexcept final;
    void setFilterEnabled(bool enabled) noexcept final;

    [[nodiscard]] auto filterEnabled() const noexcept -> bool final;

    void setInputMessages(std::vector<Types::LogEntry>&& messages);
    auto connectLogMessagesChanged(logMessageChangedSignal::slot_type slot) noexcept -> is::signals::connection;
    [[nodiscard]] auto getLogMessages() const noexcept -> const FilteredLogMessageView&;

private:
    std::vector<Types::LogEntry> m_inputMessages;
    FilteredLogMessageView m_filteredMessages;
    logMessageChangedSignal m_logMessageChangedSignal;

    std::string m_filter;
    bool m_filterEnabled = false;

    void filterMessages() noexcept;
};

} // namespace Model