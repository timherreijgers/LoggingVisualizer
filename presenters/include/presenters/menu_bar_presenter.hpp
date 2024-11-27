/*
 * Copyright © 2024 Tim Herreijgers
 * Licensed using the MIT license
 */


#pragma once

#include "model/ilog_data_context.hpp"
#include "presenters/base_presenter.hpp"
#include "presenters/settings_log_level_presenter.hpp"
#include "widgets/imenubar.hpp"

#include <memory>

namespace Presenters
{

class MenuBarPresenter : public BasePresenter
{
public:
    explicit MenuBarPresenter(Windows::IWindowManager& manager, Widgets::IMenuBar& view, Model::ILogDataContext& model);

private:
    void openFileClicked();
    void closeFileClicked() noexcept;
    void preferencesClicked() noexcept;

    Widgets::IMenuBar& m_view;
    Model::ILogDataContext& m_model;

    std::unique_ptr<SettingsLogLevelPresenter> m_settingsLogLevelPresenter;
};

} // namespace Presenters