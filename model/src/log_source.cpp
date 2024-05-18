/*
 * Copyright © 2024 Tim Herreijgers
 * Licensed using the MIT license
 */

#include "model/log_source.h"

namespace Model
{

auto LogSource::getLogEntries() const noexcept -> const std::vector<LogEntry> &
{
    static std::vector vec{
        LogEntry{"00.00.00", "INFO", "This is an info message"},
        LogEntry{"00.00.01", "WARNING", "This is an warning message"},
    };
    return vec;
}

} // namespace Model