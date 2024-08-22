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
    m_model.subscribeToLogEntriesChanged([this](const std::vector<Types::LogEntry>& data){logMessagesUpdated(data);});
    QObject::connect(&m_view, &Widgets::LogWidget::onFileDropped, [this](const std::string_view url) {onFileDroppedInView(url);});

    auto& settingsManager = Model::SettingsManager::instance();

    settingsManager.getLogLevelColorSettings().subscribe([this, &settingsManager](const auto & vector) {
        std::map<std::string, Types::HighlightColorPair> colorDataMap;
        for (const auto & entry : vector)
        {
            colorDataMap[entry.level] = {entry.textColor, entry.backgroundColor};
        }

        m_view.setHighlightColors(std::move(colorDataMap));
        settingsManager.saveSettings();
    });
}

void LogPresenter::logMessagesUpdated(const std::vector<Types::LogEntry> & logEntries) noexcept
{
    if (logEntries.empty())
    {
        m_view.clearLogMessages();
        return;
    }

    const auto & colorSettings = Model::SettingsManager::instance().getLogLevelColorSettings();
    m_view.setLogMessages(logEntries);

    std::map<std::string, Types::HighlightColorPair> colorDataMap;
    for (const auto& entry : colorSettings.getValue())
    {
        colorDataMap[entry.level] = {entry.textColor, entry.backgroundColor};
    }

    m_view.setHighlightColors(std::move(colorDataMap));
}

void LogPresenter::onFileDroppedInView(const std::string_view url)
{
    std::filesystem::path path{url};

    m_model.openFile(path);
}

} // namespace Presenters