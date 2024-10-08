/*
 * Copyright © 2024 Tim Herreijgers
 * Licensed using the MIT license
 */

#pragma once

#include "model/settings_manager.h"
#include "presenters/base_presenter.h"
#include "widgets/item_models/log_level_highlight_model.h"
#include "widgets/log_level_widget.h"

namespace Presenters
{

class SettingsLogLevelPresenter : public BasePresenter
{
public:
    SettingsLogLevelPresenter(Windows::WindowManager& manager, Widgets::LogLevelWidget& view, Model::SettingsManager& model);

private:
    void colorSelectionChanged(const int row, const Widgets::ColorType type, const Types::Color color);

    Widgets::LogLevelWidget& m_view;
    Model::SettingsManager& m_model;

    Widgets::ItemModels::LogLevelHighlightModel m_logLevelHighlightModel;
};

} // namespace Presenters