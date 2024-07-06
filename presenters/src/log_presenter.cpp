/*
 * Copyright © 2024 Tim Herreijgers
 * Licensed using the MIT license
 */

#include "presenters/log_presenter.h"

#include "model/settings_manager.h"

namespace Presenters
{

LogPresenter::LogPresenter(Widgets::LogWidget & view, Model::LogDataContext & model) :
    m_view(view), m_model(model)
{
    m_view.setLogMessages({});

    m_model.subscribeToLogEntiesChanged([this](const std::vector<Types::LogEntry>& data){logMessagesUpdated(data);});
    QObject::connect(&m_view, &Widgets::LogWidget::onFileDropped, [this](const std::string_view url) {onFileDroppedInView(url);});

    Model::SettingsManager::getLogLevelColorSettings().backgroundColor.subscribe([this](const auto & map) {
        m_view.setBackgroundColors(map);
    });

    Model::SettingsManager::getLogLevelColorSettings().textColor.subscribe([this](const auto & map) {
        m_view.setTextColors(map);
    });
}

void LogPresenter::logMessagesUpdated(const std::vector<Types::LogEntry> & logEntries) noexcept
{
    m_view.setLogMessages(logEntries);
}

void LogPresenter::onFileDroppedInView(const std::string_view url)
{
    std::filesystem::path path{url};

    m_model.openFile(path);
}

} // namespace Presenters