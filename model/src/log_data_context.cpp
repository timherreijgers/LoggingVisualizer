/*
 * Copyright © 2024 Tim Herreijgers
 * Licensed using the MIT license
 */

#include <utility>

#include "exceptions/FileNotFoundException.h"
#include "file_reader.h"
#include "model/log_data_context.h"

namespace Model
{

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

    m_logEntriesUpdatedSignal.setValue(std::move(logEntries));
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