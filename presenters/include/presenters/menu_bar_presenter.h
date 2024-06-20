/*
 * Copyright © 2024 Tim Herreijgers
 * Licensed using the MIT license
 */


#pragma once

#include "model/log_data_context.h"
#include "settings_log_level_presenter.h"
#include "widgets/menubar.h"

#include <memory>

namespace Presenters
{

class MenuBarPresenter
{
public:
    explicit MenuBarPresenter(Widgets::MenuBar& view, Model::LogDataContext& model);

private:
    void openFileClicked();
    void closeFileClicked() noexcept;
    void preferencesClicked() noexcept;

    Widgets::MenuBar& m_view;
    Model::LogDataContext& m_model;

    std::unique_ptr<SettingsLogLevelPresenter> m_settingsLogLevelPresenter;
};

} // namespace Presenters