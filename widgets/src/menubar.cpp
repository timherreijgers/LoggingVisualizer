/*
 * Copyright (c) $originalComment.match("Copyright © (\d+)", 1, "-", "$today.year")$today.year. Tim Herreijgers
 * Licensed using the MIT license
 */
 // You may need to build the project (run Qt uic code generator) to get "ui_MenuBar.h" resolved

#include "widgets/menubar.h"
#include "ui_MenuBar.h"

namespace Widgets {
MenuBar::MenuBar(QWidget *parent) :
    QMenuBar(parent), ui(new Ui::MenuBar) {
    ui->setupUi(this);
}

MenuBar::~MenuBar()
{
    delete ui;
}

} // Widgets
