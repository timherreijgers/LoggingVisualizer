/*
 * Copyright © 2024-2025 Tim Herreijgers
 * Licensed using the MIT license
 */

#include "presenters/settings_log_level_presenter.hpp"

namespace Presenters
{

SettingsLogLevelPresenter::SettingsLogLevelPresenter(Windows::IWindowManager& manager, Widgets::ILogLevelWidget& view, Model::ISettingsManager& model) :
    BasePresenter(manager), m_view(view), m_model(model)
{
    m_view.connectColorSelectionChanged([this](const int row, const Widgets::ColorType type, const Types::Color color) {
        colorSelectionChanged(row, type, color);
    });

    const auto& settingsGroup = m_model.getSettingGroup(Model::SettingsGroupId::LOG_LEVELS);
    const auto& logLevelSetting = std::get<Model::LogColorSetting>(settingsGroup.getSettings()[0]);
    for (const auto& entry : logLevelSetting.getLogColorSettingsEntries())
    {
        const auto& level = entry.getLogLevel();
        const auto textColor = entry.getForegroundColor();
        const auto backgroundColor = entry.getBackgroundColor();

        m_logLevelHighlightItemModel.addHighlightLevel(level, textColor, backgroundColor);
    }

    m_view.setModel(&m_logLevelHighlightItemModel);
}

void SettingsLogLevelPresenter::colorSelectionChanged(const int row, const Widgets::ColorType type, const Types::Color color)
{
    auto& settingsGroup = m_model.getSettingGroup(Model::SettingsGroupId::LOG_LEVELS);
    auto& logLevelSetting = std::get<Model::LogColorSetting>(settingsGroup.getSettings()[0]);

    const auto& entry = logLevelSetting.getLogColorSettingsEntries()[row];
    const auto logLevel = logLevelSetting.getLogColorSettingsEntries()[row].getLogLevel();

    switch (type)
    {
    case Widgets::ColorType::TEXT:
        logLevelSetting.getLogColorSetting(logLevel).setForegroundColor(color);
        break;
    case Widgets::ColorType::BACKGROUND:
        logLevelSetting.getLogColorSetting(logLevel).setBackgroundColor(color);
        break;
    }

    m_logLevelHighlightItemModel.changeHighlightLevel(entry.getLogLevel(), entry.getForegroundColor(), entry.getBackgroundColor());
}

} // namespace Presenters