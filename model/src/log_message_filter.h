/*
 * Copyright © 2024 Tim Herreijgers
 * Licensed using the MIT license
 */

#pragma once

#include "model/ilog_message_filter.h"
#include "types/log_entry.h"
#include "model/observable_vector.h"

#include <functional>
#include <vector>

namespace Model
{

using LogEntriesChangedListener = std::function<void(const std::vector<Types::LogEntry>&)>;

class LogMessageFilter : public ILogMessageFilter
{
public:
    void setFilter(const std::string & filter) noexcept final;
    void setFilterEnabled(bool enabled) noexcept final;

    void setInputMessages(const std::vector<Types::LogEntry>& messages) final;
    void subscribeToLogEntriesChanged(LogEntriesChangedListener listener) noexcept final;

private:
    std::vector<Types::LogEntry> m_inputMessages;
    ObservableVector<Types::LogEntry> m_observableVector;

    std::string m_filter;

    [[nodiscard]] auto filterMessages() -> std::vector<Types::LogEntry>;
};

} // namespace Model