/*
 * Copyright (c) $originalComment.match("Copyright © (\d+)", 1, "-", "$today.year")$today.year. Tim Herreijgers
 * Licensed using the MIT license
 */

#include "presenters/menu_bar_presenter.h"

#include <QApplication>
#include <QObject>

namespace Presenters
{

MenuBarPresenter::MenuBarPresenter(Widgets::MenuBar & view, Model::LogDataContext & model)
    : m_view(view), m_model(model)
{
    QObject::connect(&m_view, &Widgets::MenuBar::openFileClicked, [&]() {
        m_model.openFile("test.log");
    });

    QObject::connect(&m_view, &Widgets::MenuBar::closeFileClicked, [&]() {
        m_model.closeFile();
    });

    QObject::connect(&m_view, &Widgets::MenuBar::exitClicked, [](){QApplication::exit(0);});
}

} // namespace Presenters