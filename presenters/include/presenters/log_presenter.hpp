/*
 * Copyright © 2024 Tim Herreijgers
 * Licensed using the MIT license
 */

#pragma once

#include "model/ilog_data_context.hpp"
#include "presenters/base_presenter.hpp"
#include "widgets/ilog_widget.hpp"

namespace Presenters
{

class LogPresenter : public BasePresenter
{
public:
    explicit LogPresenter(Windows::IWindowManager& manager, Widgets::ILogWidget& view, Model::ILogDataContext& model);

private:
    void logMessagesUpdated(const Model::IFilteredLogMessageView& logEntries) noexcept;
    void onFileDroppedInView(std::string_view url);

    Widgets::ILogWidget& m_view;
    Model::ILogDataContext& m_model;
    std::unique_ptr<Widgets::ItemModels::AbstractItemModel<Types::LogEntry>> m_logModel;
};

} // namespace Presenters
