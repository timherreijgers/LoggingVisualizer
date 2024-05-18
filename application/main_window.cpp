/*
 * Copyright © 2022 Tim Herreijgers
 * Licensed using the MIT license
 */

// You may need to build the project (run Qt uic code generator) to get "ui_main_window.h" resolved

#include "main_window.h"
#include "ui_main_window.h"

namespace LoggingVisualizer {
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent), m_ui(new Ui::MainWindow) {
    m_ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete m_ui;
}

Widgets::MenuBar & MainWindow::getMenuBar() const noexcept
{
    return *m_ui->menubar;
}

Widgets::LogWidget& MainWindow::getLogWidget() const noexcept
{
    return *m_ui->logWidget;
}

} // LoggingVisualizer
