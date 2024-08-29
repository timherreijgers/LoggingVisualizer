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

namespace Model
{

using LogEntriesChangedListener = std::function<void(const std::vector<Types::LogEntry>&)>;

class ILogDataContext
{
public:
    explicit ILogDataContext() = default;
    virtual ~ILogDataContext() = default;

    virtual void openFile(const std::filesystem::path & filePath) = 0;
    virtual void closeFile() noexcept = 0;

    [[nodiscard]] virtual auto getLogMessageFilter() const noexcept -> const ILogMessageFilter& = 0;
    [[nodiscard]] virtual auto getLogMessageFilter() noexcept -> ILogMessageFilter& = 0;

    virtual void subscribeToLogEntriesChanged(LogEntriesChangedListener listener) noexcept = 0;
};

} // namespace Model