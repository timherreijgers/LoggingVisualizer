/*
 * Copyright © 2024 Tim Herreijgers
 * Licensed using the MIT license
 */

#include "model/log_data_context.h"

namespace Model
{

void LogDataContext::openFile(const std::filesystem::path &)
{
    m_logEntriesUpdatedSignal.setValue(std::vector<Types::LogEntry>{
        {"00.00.00", "DEBUG", "This is a debug message"},
        {"00.00.01", "WARNING", "This is a warning message"},
        {"00.00.02", "ERROR", "This is a error message"}
    });
}

auto LogDataContext::subscribeToLogEntiesChanged(LogEntriesChangedListener subscriber) noexcept -> void
{
    m_logEntriesUpdatedSignal.subscribe(subscriber);
}

} // namespace Model