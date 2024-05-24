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
        {"00.00.00", "TRACE", "This is a trace message"},
        {"00.00.01", "DEBUG", "This is a debug message"},
        {"00.00.02", "INFO", "This is a info message"},
        {"00.00.03", "WARNING", "This is a warning message"},
        {"00.00.04", "ERROR", "This is a error message"},
        {"00.00.05", "CRITICAL", "This is a critical message"},
});

}

void LogDataContext::closeFile() noexcept
{
    m_logEntriesUpdatedSignal.setValue({});
}

void LogDataContext::subscribeToLogEntiesChanged(LogEntriesChangedListener listener) noexcept
{
    m_logEntriesUpdatedSignal.subscribe(std::move(listener));
}

} // namespace Model