/*
 * Copyright © 2024 Tim Herreijgers
 * Licensed using the MIT license
 */

#pragma once

#include "model/log_level_color_settings.h"
#include "widgets/log_level_widget.h"

namespace Presenters
{

class SettingsLogLevelPresenter
{
public:
    SettingsLogLevelPresenter(Widgets::LogLevelWidget & view, Model::LogLevelColorSettings& model);

private:
    void colorSelectionChanged(const int row, const Widgets::ColorType type, const Types::Color color);

    Widgets::LogLevelWidget & m_view;
    Model::LogLevelColorSettings& m_model;
};

} // namespace Presenters