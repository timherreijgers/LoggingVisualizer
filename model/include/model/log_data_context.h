/*
 * Copyright © 2024 Tim Herreijgers
 * Licensed using the MIT license
 */

#pragma once

#include "model/observable.h"

#include "types/log_entry.h"

#include <vector>
#include <filesystem>

namespace Model
{

using LogEntriesChangedListener = std::function<void(const std::vector<Types::LogEntry>&)>;

class LogDataContext
{
public:
    explicit LogDataContext() = default;

    void openFile(const std::filesystem::path & filePath);
    void closeFile() noexcept;

    void subscribeToLogEntiesChanged(LogEntriesChangedListener listener) noexcept;
private:
    Observable<std::vector<Types::LogEntry>> m_logEntriesUpdatedSignal;
};

} // namespace Model