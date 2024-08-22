/*
 * Copyright © 2024 Tim Herreijgers
 * Licensed using the MIT license
 */

#pragma once

#include "ilog_message_filter.h"
#include "types/log_entry.h"

#include <vector>
#include <filesystem>
#include <functional>
#include <memory>

namespace Model
{

using LogEntriesChangedListener = std::function<void(const std::vector<Types::LogEntry>&)>;

class LogDataContext
{
public:
    explicit LogDataContext();

    void openFile(const std::filesystem::path & filePath);
    void closeFile() noexcept;

    [[nodiscard]] auto getLogMessageFilter() const noexcept -> const ILogMessageFilter&;
    [[nodiscard]] auto getLogMessageFilter() noexcept -> ILogMessageFilter&;

    void subscribeToLogEntriesChanged(LogEntriesChangedListener listener) noexcept;

private:
    std::unique_ptr<ILogMessageFilter> m_logMessageFilter;
};

} // namespace Model