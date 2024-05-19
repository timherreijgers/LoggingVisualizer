/*
 * Copyright © 2024 Tim Herreijgers
 * Licensed using the MIT license
 */

#include <QApplication>

#include "main_window.h"
#include "model/log_data_context.h"
#include "presenters/log_presenter.h"
#include "presenters/menu_bar_presenter.h"

int main(int argc, char **argv)
{
    QApplication application(argc, argv);

    LoggingVisualizer::MainWindow mainWindow;
    mainWindow.show();

    Model::LogDataContext logDataContext{};
    Presenters::LogPresenter logPresenter(mainWindow.getLogWidget(), logDataContext);
    Presenters::MenuBarPresenter menuBarPresenter(mainWindow.getMenuBar(), logDataContext);

    return QApplication::exec();
}