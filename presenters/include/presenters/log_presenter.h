/*
 * Copyright © 2024 Tim Herreijgers
 * Licensed using the MIT license
 */

#pragma once

#include "model/ilog_data_context.h"
#include "types/log_entry.h"
#include "widgets/log_widget.h"

#include <vector>

namespace Presenters
{

class LogPresenter
{
public:
    explicit LogPresenter(Widgets::LogWidget& view, Model::ILogDataContext& model);

private:
    void logMessagesUpdated(const std::vector<Types::LogEntry>& logEntries) noexcept;
    void onFileDroppedInView(std::string_view url);

    Widgets::LogWidget & m_view;
    Model::ILogDataContext& m_model;
};

} // namespace Presenters
