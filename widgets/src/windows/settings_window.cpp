/*
 * Copyright © 2024 Tim Herreijgers
 * Licensed using the MIT license
 */

// You may need to build the project (run Qt uic code generator) to get "ui_settings_window.h" resolved

#include "windows/settings_window.h"
#include "ui_settings_window.h"

namespace Windows {
SettingsWindow::SettingsWindow(QWidget *parent) :
    QMainWindow(parent), ui(new Ui::SettingsWindow) {
    ui->setupUi(this);
}

SettingsWindow::~SettingsWindow() {
    delete ui;
}
} // Windows
