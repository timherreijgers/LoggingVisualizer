/*
 * Copyright © 2024 Tim Herreijgers
 * Licensed using the MIT license
 */

#pragma once

#include "ilog_message_filter.h"
#include "types/log_entry.h"
#include "ifiltered_log_message_view.h"

#include "libfastsignals/signal.h"

#include <filesystem>
#include <vector>

namespace Model
{

using logMessageChangedSignal = is::signals::signal<void()>;

class ILogDataContext
{
public:
    explicit ILogDataContext() = default;

    virtual ~ILogDataContext() = default;
    ILogDataContext(const ILogDataContext&) = delete;
    ILogDataContext& operator=(const ILogDataContext&) = delete;
    ILogDataContext(ILogDataContext&&) = delete;
    ILogDataContext& operator=(ILogDataContext&&) = delete;

    virtual void openFile(const std::filesystem::path & filePath) = 0;
    virtual void closeFile() noexcept = 0;

    [[nodiscard]] virtual auto getLogMessageFilter() const noexcept -> const ILogMessageFilter& = 0;
    [[nodiscard]] virtual auto getLogMessageFilter() noexcept -> ILogMessageFilter& = 0;

    [[nodiscard]] virtual auto getLogMessages() const noexcept -> const IFilteredLogMessageView& = 0;

    virtual auto connectLogMessagesChanged(logMessageChangedSignal::slot_type slot) noexcept -> is::signals::connection = 0;
};

} // namespace Model