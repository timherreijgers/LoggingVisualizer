/*
 * Copyright © 2024 Tim Herreijgers
 * Licensed using the MIT license
 */

#include "windows/main_window.h"

#include "ui_main_window.h"

namespace Windows
{

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent), m_ui(std::make_unique<Ui::MainWindow>()) {
    m_ui->setupUi(this);
}

MainWindow::~MainWindow() = default;

Widgets::MenuBar & MainWindow::getMenuBar() const noexcept
{
    return *m_ui->menubar;
}

Widgets::LogWidget & MainWindow::getLogWidget() const noexcept
{
    return *m_ui->logWidget;
}
auto MainWindow::getToolbar() const noexcept -> Widgets::Toolbar &
{
    return *m_ui->toolbar;
}

} // Windows
