/*
 * Copyright © 2024 Tim Herreijgers
 * Licensed using the MIT license
 */

#pragma once

#include "model/ilog_message_filter.h"
#include "types/log_entry.h"

#include "libfastsignals/signal.h"

#include <vector>

namespace Model
{

using logMessageChangedSignal = is::signals::signal<void()>;

class LogMessageFilter : public ILogMessageFilter
{
public:
    void setFilter(const std::string & filter) noexcept final;
    void setFilterEnabled(bool enabled) noexcept final;

    [[nodiscard]] auto filterEnabled() const noexcept -> bool final;

    void setInputMessages(const std::vector<Types::LogEntry>& messages);
    auto connectLogMessagesChanged(logMessageChangedSignal::slot_type slot) noexcept -> is::signals::connection;
    [[nodiscard]] auto getLogMessages() const noexcept -> const std::vector<Types::LogEntry>&;

private:
    std::vector<Types::LogEntry> m_inputMessages;
    std::vector<Types::LogEntry> m_outputMessages;
    logMessageChangedSignal m_logMessageChangedSignal;

    std::string m_filter;
    bool m_filterEnabled = true;

    [[nodiscard]] auto filterMessages() noexcept -> std::vector<Types::LogEntry>;
};

} // namespace Model