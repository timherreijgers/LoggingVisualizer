/*
 * Copyright © 2024 Tim Herreijgers
 * Licensed using the MIT license
 */

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
