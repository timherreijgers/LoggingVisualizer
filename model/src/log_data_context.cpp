/*
 * Copyright © 2024 Tim Herreijgers
 * Licensed using the MIT license
 */

#include <utility>

#include "model/log_data_context.h"

namespace Model
{

void LogDataContext::openFile(const std::filesystem::path &)
{
    m_logEntriesUpdatedSignal.setValue(std::vector<Types::LogEntry>{
        {"00.00.00", "DEBUG", "This is a debug message"},
        {"00.00.01", "WARNING", "This is a warning message"},
        {"00.00.02", "ERROR", "This is a error message"}});
}

void LogDataContext::closeFile() noexcept
{
    m_logEntriesUpdatedSignal.setValue({});
}

void LogDataContext::subscribeToLogEntiesChanged(LogEntriesChangedListener subscriber) noexcept
{
    m_logEntriesUpdatedSignal.subscribe(std::move(subscriber));
}

} // namespace Model