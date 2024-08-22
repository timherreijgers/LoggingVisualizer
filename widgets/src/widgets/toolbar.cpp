/*
 * Copyright © 2024 Tim Herreijgers
 * Licensed using the MIT license
 */

// You may need to build the project (run Qt uic code generator) to get "ui_Toolbar.h" resolved

#include "widgets/toolbar.h"

#include "ui_toolbar.h"

namespace Widgets
{
Toolbar::Toolbar(QWidget *parent) :
    QWidget(parent), ui(new Ui::Toolbar) {
    ui->setupUi(this);
}

Toolbar::~Toolbar() {
    delete ui;
}

} // namespace Widgets
