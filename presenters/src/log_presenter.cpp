/*
 * Copyright © 2024 Tim Herreijgers
 * Licensed using the MIT license
 */

#include "presenters/log_presenter.h"

#include "item_models/log_item_model.h"
#include "model/settings_manager.h"

namespace Presenters
{

LogPresenter::LogPresenter(Windows::WindowManager& manager, Widgets::LogWidget& view, Model::ILogDataContext& model) :
    BasePresenter(manager), m_view(view), m_model(model)
{
    m_model.connectLogMessagesChanged([this]() { logMessagesUpdated(m_model.getLogMessages()); });
    QObject::connect(&m_view, &Widgets::LogWidget::onFileDropped, [this](const std::string_view url) { onFileDroppedInView(url); });

    auto& settingsManager = Model::SettingsManager::instance();

    settingsManager.getLogLevelColorSettings().subscribe([this, &settingsManager](const auto& vector) {
        std::map<std::string, Types::HighlightColorPair> colorDataMap;
        for (const auto& entry : vector)
        {
            colorDataMap[entry.level] = {entry.textColor, entry.backgroundColor};
        }

        m_view.setHighlightColors(std::move(colorDataMap));
        settingsManager.saveSettings();
    });
}

void LogPresenter::logMessagesUpdated(const Model::IFilteredLogMessageView& logEntries) noexcept
{
    if (logEntries.empty())
    {
        m_view.clearLogMessages();
        return;
    }

    m_logModel = std::make_unique<LogItemModel>(logEntries);
    m_view.setLogMessages(*m_logModel);

    const auto& colorSettings = Model::SettingsManager::instance().getLogLevelColorSettings();

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