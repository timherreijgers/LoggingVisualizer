/*
 * Copyright © 2024 Tim Herreijgers
 * Licensed using the MIT license
 */


#pragma once

#include "model/ilog_data_context.h"
#include "presenters/base_presenter.h"
#include "presenters/settings_log_level_presenter.h"
#include "widgets/menubar.h"

#include <memory>

namespace Presenters
{

class MenuBarPresenter : public BasePresenter
{
public:
    explicit MenuBarPresenter(Windows::WindowManager& manager, Widgets::MenuBar& view, Model::ILogDataContext& model);

private:
    void openFileClicked();
    void closeFileClicked() noexcept;
    void preferencesClicked() noexcept;

    Widgets::MenuBar& m_view;
    Model::ILogDataContext& m_model;

    std::unique_ptr<SettingsLogLevelPresenter> m_settingsLogLevelPresenter;
};

} // namespace Presenters