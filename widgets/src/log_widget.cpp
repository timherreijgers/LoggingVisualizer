/*
 * Copyright © 2024 Tim Herreijgers
 * Licensed using the MIT license
 */

// You may need to build the project (run Qt uic code generator) to get "ui_log_widget.h" resolved

#include "../include/log_widget.h"
#include "ui_log_widget.h"


LogWidget::LogWidget(QWidget * parent) :
    QWidget(parent), ui(new Ui::LogWidget)
{
    ui->setupUi(this);
}

LogWidget::~LogWidget()
{
    delete ui;
}
