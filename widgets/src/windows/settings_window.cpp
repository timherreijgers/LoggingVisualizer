/*
 * Copyright © 2024-2025 Tim Herreijgers
 * Licensed using the MIT license
 */

#include "windows/settings_window.hpp"

#include "ui_settings_window.h"

namespace Windows
{

SettingsWindow::SettingsWindow(QWidget * parent) :
    QMainWindow(parent), m_ui(std::make_unique<Ui::SettingsWindow>())
{
    m_ui->setupUi(this);
}

SettingsWindow::~SettingsWindow() = default;

Widgets::ILogLevelWidget& SettingsWindow::getLogLevelWidget() const noexcept
{
    return *m_ui->debug_levels_table;
}

void SettingsWindow::showWindow()
{
    QMainWindow::show();
}

} // namespace Windows
