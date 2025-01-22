/*
 * Copyright © 2024-2025 Tim Herreijgers
 * Licensed using the MIT license
 */

#pragma once

#include "model/ilog_data_context.hpp"
#include "model/isettings_manager.hpp"
#include "presenters/base_presenter.hpp"
#include "widgets/ilog_widget.hpp"

namespace Presenters
{

class LogPresenter : public BasePresenter
{
public:
    explicit LogPresenter(Windows::IWindowManager& manager, Widgets::ILogWidget& view, Model::ILogDataContext& model, Model::ISettingsManager& settingsManager);
    ~LogPresenter() override;

private:
    void logMessagesUpdated(const Model::IFilteredLogMessageView& logEntries) noexcept;
    void onFileDroppedInView(std::string_view url);

    Widgets::ILogWidget& m_view;
    Model::ILogDataContext& m_model;
    Model::ISettingsManager& m_settingsManager;

    std::unique_ptr<Widgets::ItemModels::AbstractItemModel<Types::LogEntry>> m_logModel;
    // TODO: There should be an RAII wrapper for this, so we can get rid of the destructor to adhere to the rule of 0
    Signals::connection m_settingsChangedConnection;
};

} // namespace Presenters
