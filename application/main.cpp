/*
 * Copyright © 2024 Tim Herreijgers
 * Licensed using the MIT license
 */

#include <QApplication>

#include "main_window.h"

int main(int argc, char **argv)
{
    QApplication application(argc, argv);

    LoggingVisualizer::MainWindow mainWindow;
    mainWindow.show();

    return QApplication::exec();
}