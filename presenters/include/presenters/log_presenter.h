/*
 * Copyright © 2024 Tim Herreijgers
 * Licensed using the MIT license
 */

#pragma once

#include "model/log_data_context.h"
#include "widgets/log_widget.h"

#include <vector>

namespace Model
{
struct LogEntry;
}
namespace Presenters
{

class LogPresenter
{
public:
    explicit LogPresenter(Widgets::LogWidget& view, Model::LogDataContext& model);

private:
    void logMessagesUpdated(const std::vector<Types::LogEntry>& logEntries) noexcept;
    void onFileDroppedInView(std::string_view url);

    Widgets::LogWidget & m_view;
    Model::LogDataContext& m_model;
};

} // namespace Presenters
