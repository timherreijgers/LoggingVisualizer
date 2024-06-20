/*
 * Copyright © 2024 Tim Herreijgers
 * Licensed using the MIT license
 */

#include "presenters/settings_log_level_presenter.h"

#include "model/settings_manager.h"

#include <array>

namespace Presenters
{

SettingsLogLevelPresenter::SettingsLogLevelPresenter(Widgets::LogLevelWidget & view, Model::LogLevelColorSettings & model) :
    m_view(view), m_model(model)
{
    QObject::connect(&m_view, &Widgets::LogLevelWidget::colorSelectionChanged, [this](const int row, const Widgets::ColorType type, const Types::Color color) {
        colorSelectionChanged(row, type, color);
    });
}

void SettingsLogLevelPresenter::colorSelectionChanged(const int row, const Widgets::ColorType type, const Types::Color color)
{
    static constexpr std::array logLevels = {"TRACE", "DEBUG", "INFO", "WARNING", "ERROR", "CRITICAL"};

    switch (type)
    {
        case Widgets::ColorType::TEXT:
            m_model.textColor[logLevels[row]] = color;
            return;
        case Widgets::ColorType::BACKGROUND:
            m_model.backgroundColor[logLevels[row]] = color;
            return;
    }
}

} // namespace Presenters