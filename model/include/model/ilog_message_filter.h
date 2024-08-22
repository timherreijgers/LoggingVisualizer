/*
 * Copyright © 2024 Tim Herreijgers
 * Licensed using the MIT license
 */

#pragma once

#include "types/log_entry.h"


#include <functional>
#include <string>

namespace Model
{

using LogEntriesChangedListener = std::function<void(const std::vector<Types::LogEntry> &)>;

class ILogMessageFilter
{
public:
    ILogMessageFilter() = default;
    virtual ~ILogMessageFilter() = default;
    // TODO: timher Would the interface need to follow the rule of 5?
    ILogMessageFilter(const ILogMessageFilter&) = delete;
    ILogMessageFilter& operator=(const ILogMessageFilter&) = delete;
    ILogMessageFilter(ILogMessageFilter&&) = delete;
    ILogMessageFilter& operator=(ILogMessageFilter&&) = delete;

    virtual void setFilter(const std::string& filter) noexcept = 0;
    virtual void setFilterEnabled(bool enabled) noexcept = 0;
    // TODO: timher Remove these functions when we move to an interface for LogDataContext
    virtual void setInputMessages(const std::vector<Types::LogEntry>& messages) = 0;
    virtual void subscribeToLogEntriesChanged(LogEntriesChangedListener listener) noexcept = 0;
};

}