/*
 * Copyright © 2024 Tim Herreijgers
 * Licensed using the MIT license
 */

#pragma once

#include "widgets/log_level_widget.h"
#include "model/settings_model.h"

namespace Presenters
{

class SettingsLogLevelPresenter
{
public:
    SettingsLogLevelPresenter(Widgets::LogLevelWidget & m_view, Model::SettingsModel& m_model);

private:
    Widgets::LogLevelWidget & m_view;
    Model::SettingsModel& m_model;
};

} // namespace Presenters