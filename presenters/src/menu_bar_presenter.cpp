/*
 * Copyright © 2024 Tim Herreijgers
 * Licensed using the MIT license
 */

#include "presenters/menu_bar_presenter.h"

#include "model/settings_manager.h"
#include "windows/window_manager.h"

#include <QApplication>
#include <QFileDialog>
#include <QObject>

namespace Presenters
{

MenuBarPresenter::MenuBarPresenter(Widgets::MenuBar & view, Model::LogDataContext & model) :
    m_view(view), m_model(model)
{
    QObject::connect(&m_view, &Widgets::MenuBar::openFileClicked, [this]() { openFileClicked(); });
    QObject::connect(&m_view, &Widgets::MenuBar::closeFileClicked, [this]() { closeFileClicked(); });
    QObject::connect(&m_view, &Widgets::MenuBar::preferencesClicked, [this](){ preferencesClicked(); });
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
    auto &settingsWindow = Windows::WindowManager::createSettingsWindow();
    if (!m_settingsLogLevelPresenter)
        m_settingsLogLevelPresenter = std::make_unique<SettingsLogLevelPresenter>(settingsWindow.getLogWidget(), Model::SettingsManager::getLogLevelColorSettings());

    settingsWindow.show();
}

} // namespace Presenters