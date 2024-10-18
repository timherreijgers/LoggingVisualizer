/*
 * Copyright © 2024 Tim Herreijgers
 * Licensed using the MIT license
 */

#pragma once

#include "ifile_reader.h"
#include "model/ilog_data_context.h"

#include "log_message_filter.h"

#include <filesystem>

namespace Model
{

class LogDataContext : public ILogDataContext
{
public:
    explicit LogDataContext(std::unique_ptr<IFileReader> file_reader);
    ~LogDataContext() override = default;

    void openFile(const std::filesystem::path& filePath) final;
    void closeFile() noexcept final;

    [[nodiscard]] auto getLogMessageFilter() const noexcept -> const ILogMessageFilter& final;
    [[nodiscard]] auto getLogMessageFilter() noexcept -> ILogMessageFilter& final;

    [[nodiscard]] auto getLogMessages() const noexcept -> const IFilteredLogMessageView& final;

    auto connectLogMessagesChanged(logMessageChangedSignal::slot_type slot) noexcept -> is::signals::connection final;

private:
    std::unique_ptr<IFileReader> m_fileReader;
    LogMessageFilter m_logMessageFilter;
};

} // namespace Model