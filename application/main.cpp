/*
 * Copyright © 2024 Tim Herreijgers
 * Licensed using the MIT license
 */

#include <QApplication>

#include "main_window.h"
#include "presenters/log_presenter.h"
#include "model/log_source.h"

int main(int argc, char **argv)
{
    QApplication application(argc, argv);

    LoggingVisualizer::MainWindow mainWindow;
    mainWindow.show();

    Presenters::LogPresenter logPresenter(mainWindow.getLogWidget(), Model::LogSource{});

    return QApplication::exec();
}