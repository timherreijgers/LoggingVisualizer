/*
 * Copyright © 2024 Tim Herreijgers
 * Licensed using the MIT license
 */

#pragma once

#include "types/log_entry.h"
#include "model/ilog_data_context.h"

#include "log_message_filter.h"

#include <filesystem>
#include <functional>
#include <vector>

namespace Model
{

using LogEntriesChangedListener = std::function<void(const std::vector<Types::LogEntry>&)>;

class LogDataContext : public ILogDataContext
{
public:
    explicit LogDataContext() = default;
    ~LogDataContext() override = default;

    void openFile(const std::filesystem::path & filePath) final;
    void closeFile() noexcept final;

    [[nodiscard]] auto getLogMessageFilter() const noexcept -> const ILogMessageFilter& final;
    [[nodiscard]] auto getLogMessageFilter() noexcept -> ILogMessageFilter& final;

    void subscribeToLogEntriesChanged(LogEntriesChangedListener listener) noexcept final;

private:
    LogMessageFilter m_logMessageFilter;
};

} // namespace Model