/*
 * Copyright © 2024 Tim Herreijgers
 * Licensed using the MIT license
 */

#pragma once

#include "model/ilog_data_context.h"
#include "presenters/base_presenter.h"
#include "widgets/log_widget.h"

namespace Presenters
{

class LogPresenter : public BasePresenter
{
public:
    explicit LogPresenter(Windows::WindowManager& manager, Widgets::LogWidget& view, Model::ILogDataContext& model);

private:
    void logMessagesUpdated(const Model::IFilteredLogMessageView& logEntries) noexcept;
    void onFileDroppedInView(std::string_view url);

    Widgets::LogWidget& m_view;
    Model::ILogDataContext& m_model;
    std::unique_ptr<Widgets::ItemModels::AbstractItemModel<Types::LogEntry>> m_logModel;
};

} // namespace Presenters
