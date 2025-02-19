/*
 * Copyright © 2024-2025 Tim Herreijgers
 * Licensed using the MIT license
 */

#pragma once

#include "ifiltered_log_message_view.hpp"
#include "ilog_message_filter.hpp"

#include "model/signal.hpp"

#include <filesystem>

namespace Model
{

using logMessageChangedSignal = Signals::signal<void()>;

class ILogDataContext
{
public:
    explicit ILogDataContext() = default;

    virtual ~ILogDataContext() = default;
    ILogDataContext(const ILogDataContext&) = delete;
    ILogDataContext& operator=(const ILogDataContext&) = delete;
    ILogDataContext(ILogDataContext&&) = delete;
    ILogDataContext& operator=(ILogDataContext&&) = delete;

    virtual void openFile(const std::filesystem::path& filePath) = 0;
    virtual void closeFile() noexcept = 0;

    [[nodiscard]] virtual auto getLogMessageFilter() noexcept -> ILogMessageFilter& = 0;

    [[nodiscard]] virtual auto getLogMessages() const noexcept -> const IFilteredLogMessageView& = 0;

    virtual auto connectLogMessagesChanged(logMessageChangedSignal::slot_type slot) noexcept -> is::signals::connection = 0;
};

} // namespace Model