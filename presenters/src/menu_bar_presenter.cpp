/*
 * Copyright © 2024 Tim Herreijgers
 * Licensed using the MIT license
 */

#include "presenters/menu_bar_presenter.hpp"

#include "model/settings_manager.hpp"
#include "windows/window_manager.hpp"

#include <QApplication>
#include <QFileDialog>
#include <QObject>

namespace Presenters
{

MenuBarPresenter::MenuBarPresenter(Windows::IWindowManager& manager, Widgets::IMenuBar& view, Model::ILogDataContext& model) :
    BasePresenter(manager), m_view(view), m_model(model)
{
    m_view.connectOpenFileClicked([this]() { openFileClicked(); });
    m_view.connectCloseFileClicked([this]() { closeFileClicked(); });
    m_view.connectPreferencesClicked([this]() { preferencesClicked(); });
    m_view.connectExitClicked([]() { QApplication::exit(0); });
}

void MenuBarPresenter::openFileClicked()
{
    const auto filename = QFileDialog::getOpenFileName().toStdString();
    m_model.openFile(filename);
}

void MenuBarPresenter::closeFileClicked() noexcept
{
    m_model.closeFile();
}

void MenuBarPresenter::preferencesClicked() noexcept
{
    auto& settingsWindow = getWindowManager().getSettingsWindow();
    if (!m_settingsLogLevelPresenter)
        m_settingsLogLevelPresenter = std::make_unique<SettingsLogLevelPresenter>(getWindowManager(), settingsWindow.getLogWidget(), Model::SettingsManager::instance());

    settingsWindow.show();
}

} // namespace Presenters