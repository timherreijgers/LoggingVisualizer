/*
 * Copyright © 2024 Tim Herreijgers
 * Licensed using the MIT license
 */

#include "file_reader.h"

#include "exceptions/FileNotFoundException.h"
#include "log_data_context.h"

#include "log_message_filter.h"

namespace Model
{

LogDataContext::LogDataContext()
    : m_logMessageFilter(std::make_unique<LogMessageFilter>())
{
}

void LogDataContext::openFile(const std::filesystem::path & path)
{
    FileReader reader{path};
    if (!reader.exists())
        throw Exceptions::FileNotFoundException(path);

    std::vector<Types::LogEntry> logEntries{};

    while(reader.hasNextLine())
    {
        const auto line = reader.readNextLine();

        const auto timeStart = line.find('[', 0) + 1;
        const auto timeEnd = line.find(']', timeStart);

        const auto levelStart = line.find('[', timeEnd) + 1;
        const auto levelEnd = line.find(']', levelStart);

        Types::LogEntry entry = {
            line.substr(timeStart, timeEnd - timeStart),
            line.substr(levelStart, levelEnd - levelStart),
            line.substr(levelEnd + 1, line.size() - levelEnd - 1)
        };
        logEntries.push_back(entry);
    }

    m_logMessageFilter->setInputMessages(logEntries);
}

void LogDataContext::closeFile() noexcept
{
    m_logMessageFilter->setInputMessages({});
}

auto LogDataContext::getLogMessageFilter() const noexcept -> const ILogMessageFilter &
{
    return *m_logMessageFilter;
}

auto LogDataContext::getLogMessageFilter() noexcept -> ILogMessageFilter &
{
    return *m_logMessageFilter;
}

void LogDataContext::subscribeToLogEntriesChanged(LogEntriesChangedListener listener) noexcept
{
    m_logMessageFilter->subscribeToLogEntriesChanged(std::move(listener));
}

} // namespace Model