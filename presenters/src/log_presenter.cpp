/*
 * Copyright © 2024-2025 Tim Herreijgers
 * Licensed using the MIT license
 */

#include "presenters/log_presenter.hpp"

#include "item_models/log_item_model.hpp"
#include "model/settings_manager.hpp"

namespace Presenters
{

LogPresenter::LogPresenter(Windows::IWindowManager& manager, Widgets::ILogWidget& view, Model::ILogDataContext& model) :
    BasePresenter(manager), m_view(view), m_model(model)
{
    m_model.connectLogMessagesChanged([this]() { logMessagesUpdated(m_model.getLogMessages()); });
    m_view.connectOnFileDropped([this](const std::string_view url) { onFileDroppedInView(url); });

    auto& settingsManager = Model::SettingsManager::instance();

    m_settingsChangedConnection = settingsManager.connectSettingsChangedSignal([this, &settingsManager]() {
        std::map<std::string, Types::HighlightColorPair> colorDataMap;
        for (const auto& entry : settingsManager.getLogLevelColorSettings())
        {
            colorDataMap[entry.level] = {entry.textColor, entry.backgroundColor};
        }

        m_view.setHighlightColors(std::move(colorDataMap));
        settingsManager.saveSettings();
    });
}

LogPresenter::~LogPresenter()
{
    m_settingsChangedConnection.disconnect();
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
    for (const auto& entry : colorSettings)
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