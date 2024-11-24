/*
 * Copyright © 2024 Tim Herreijgers
 * Licensed using the MIT license
 */

#include "presenters/settings_log_level_presenter.hpp"

namespace Presenters
{

SettingsLogLevelPresenter::SettingsLogLevelPresenter(Windows::WindowManager& manager, Widgets::ILogLevelWidget& view, Model::SettingsManager& model) :
    BasePresenter(manager), m_view(view), m_model(model)
{
    m_view.connectColorSelectionChanged([this](const int row, const Widgets::ColorType type, const Types::Color color) {
        colorSelectionChanged(row, type, color);
    });

    for (const auto& entry : m_model.getLogLevelColorSettings())
    {
        const auto& level = entry.level;
        const auto textColor = entry.textColor;
        const auto backgroundColor = entry.backgroundColor;

        m_logLevelHighlightModel.addHighlightLevel(level, textColor, backgroundColor);
    }

    m_view.setModel(&m_logLevelHighlightModel);
}

void SettingsLogLevelPresenter::colorSelectionChanged(const int row, const Widgets::ColorType type, const Types::Color color)
{
    const Model::LogLevelColorSettingsEntry& cachedValue = m_model.getLogLevelColorSettings()[row];

    switch (type)
    {
    case Widgets::ColorType::TEXT:
        m_model.setLogLevelColorSettings(cachedValue.level, color, cachedValue.backgroundColor);
        break;
    case Widgets::ColorType::BACKGROUND:
        m_model.setLogLevelColorSettings(cachedValue.level, cachedValue.textColor, color);
        break;
    }

    const Model::LogLevelColorSettingsEntry& value = m_model.getLogLevelColorSettings()[row];
    m_logLevelHighlightModel.changeHighlightLevel(value.level, value.textColor, value.backgroundColor);
}

} // namespace Presenters