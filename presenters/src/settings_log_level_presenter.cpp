/*
 * Copyright © 2024 Tim Herreijgers
 * Licensed using the MIT license
 */

#include "presenters/settings_log_level_presenter.h"

#include <array>

namespace Presenters
{

SettingsLogLevelPresenter::SettingsLogLevelPresenter(Widgets::LogLevelWidget & view, Model::SettingsManager & model) :
    m_view(view), m_model(model)
{
    QObject::connect(&m_view, &Widgets::LogLevelWidget::colorSelectionChanged, [this](const int row, const Widgets::ColorType type, const Types::Color color) {
        colorSelectionChanged(row, type, color);
    });

    for (const auto & entry : m_model.getLogLevelColorSettings().getValue())
    {
        const auto level = entry.level;
        const auto textColor = entry.textColor;
        const auto backgroundColor = entry.backgroundColor;

        m_logLevelHighlightModel.addHighlightLevel(level, textColor, backgroundColor);
    }

    m_view.setModel(&m_logLevelHighlightModel);
}

void SettingsLogLevelPresenter::colorSelectionChanged(const int row, const Widgets::ColorType type, const Types::Color color)
{
    static constexpr std::array logLevels = {"TRACE", "DEBUG", "INFO", "WARNING", "ERROR", "CRITICAL"};

    const Model::LogLevelColorSettingsEntry& cachedValue = m_model.getLogLevelColorSettings()[row];

    switch (type)
    {
        case Widgets::ColorType::TEXT:
            m_model.getLogLevelColorSettings()[row] = {cachedValue.level, color, cachedValue.backgroundColor};
            break;
        case Widgets::ColorType::BACKGROUND:
            m_model.getLogLevelColorSettings()[row] = {cachedValue.level, cachedValue.textColor, color};
            break;
    }
}

} // namespace Presenters