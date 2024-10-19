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

MenuBarPresenter::MenuBarPresenter(Windows::WindowManager& manager, Widgets::MenuBar& view, Model::ILogDataContext& model) :
    BasePresenter(manager), m_view(view), m_model(model)
{
    QObject::connect(&m_view, &Widgets::MenuBar::openFileClicked, [this]() { openFileClicked(); });
    QObject::connect(&m_view, &Widgets::MenuBar::closeFileClicked, [this]() { closeFileClicked(); });
    QObject::connect(&m_view, &Widgets::MenuBar::preferencesClicked, [this]() { preferencesClicked(); });
    QObject::connect(&m_view, &Widgets::MenuBar::exitClicked, []() { QApplication::exit(0); });
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