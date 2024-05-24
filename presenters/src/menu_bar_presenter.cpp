/*
 * Copyright © 2024 Tim Herreijgers
 * Licensed using the MIT license
 */

#include "presenters/menu_bar_presenter.h"

#include <QApplication>
#include <QObject>

namespace Presenters
{

MenuBarPresenter::MenuBarPresenter(Widgets::MenuBar & view, Model::LogDataContext & model) :
    m_view(view), m_model(model)
{
    QObject::connect(&m_view, &Widgets::MenuBar::openFileClicked, [this] { openFileClicked(); });
    QObject::connect(&m_view, &Widgets::MenuBar::closeFileClicked, [this] { closeFileClicked(); });
    QObject::connect(&m_view, &Widgets::MenuBar::exitClicked, []() { QApplication::exit(0); });
}

void MenuBarPresenter::openFileClicked()
{
    m_model.openFile("test.log");
}

void MenuBarPresenter::closeFileClicked() noexcept
{
    m_model.closeFile();
}

} // namespace Presenters