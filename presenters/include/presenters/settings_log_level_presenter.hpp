/*
 * Copyright © 2024 Tim Herreijgers
 * Licensed using the MIT license
 */

#pragma once

#include "model/settings_manager.hpp"
#include "presenters/base_presenter.hpp"
#include "widgets/ilog_level_widget.hpp"
#include "widgets/item_models/log_level_highlight_model.hpp"

namespace Presenters
{

class SettingsLogLevelPresenter : public BasePresenter
{
public:
    SettingsLogLevelPresenter(Windows::IWindowManager& manager, Widgets::ILogLevelWidget& view, Model::SettingsManager& model);

private:
    void colorSelectionChanged(const int row, const Widgets::ColorType type, const Types::Color color);

    Widgets::ILogLevelWidget& m_view;
    Model::SettingsManager& m_model;

    Widgets::ItemModels::LogLevelHighlightModel m_logLevelHighlightModel;
};

} // namespace Presenters