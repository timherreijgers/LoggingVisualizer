/*
 * Copyright © 2024 Tim Herreijgers
 * Licensed using the MIT license
 */

#pragma once

#include "model/settings_manager.hpp"
#include "presenters/base_presenter.hpp"
#include "widgets/item_models/log_level_highlight_model.hpp"
#include "widgets/log_level_widget.hpp"

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