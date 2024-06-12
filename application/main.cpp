/*
 * Copyright © 2024 Tim Herreijgers
 * Licensed using the MIT license
 */

#include <QApplication>

#include "model/log_data_context.h"
#include "presenters/log_presenter.h"
#include "presenters/menu_bar_presenter.h"
#include "windows/main_window.h"
#include "windows/window_manager.h"

int main(int argc, char **argv)
{
    QApplication application(argc, argv);

    auto &mainWindow = Windows::WindowManager::createMainWindow();
    mainWindow.show();

    Model::LogDataContext logDataContext{};
    Presenters::LogPresenter logPresenter(mainWindow.getLogWidget(), logDataContext);
    Presenters::MenuBarPresenter menuBarPresenter(mainWindow.getMenuBar(), logDataContext);

    return QApplication::exec();
}