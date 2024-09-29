/*
 * Copyright © 2024 Tim Herreijgers
 * Licensed using the MIT license
 */

#pragma once

#include "model/ilog_data_context.h"
#include "types/log_entry.h"

#include "log_message_filter.h"

#include <filesystem>
#include <vector>

namespace Model
{

class LogDataContext : public ILogDataContext
{
public:
    explicit LogDataContext() = default;
    ~LogDataContext() override = default;

    void openFile(const std::filesystem::path& filePath) final;
    void closeFile() noexcept final;

    [[nodiscard]] auto getLogMessageFilter() const noexcept -> const ILogMessageFilter& final;
    [[nodiscard]] auto getLogMessageFilter() noexcept -> ILogMessageFilter& final;

    [[nodiscard]] auto getLogMessages() const noexcept -> const IFilteredLogMessageView& final;

    auto connectLogMessagesChanged(logMessageChangedSignal::slot_type slot) noexcept -> is::signals::connection final;

private:
    LogMessageFilter m_logMessageFilter;
};

} // namespace Model