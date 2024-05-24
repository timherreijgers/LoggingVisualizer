/*
 * Copyright (c) $originalComment.match("Copyright © (\d+)", 1, "-", "$today.year")$today.year. Tim Herreijgers
 * Licensed using the MIT license
 */
 // You may need to build the project (run Qt uic code generator) to get "ui_MenuBar.h" resolved

#include "widgets/menubar.h"
#include "ui_MenuBar.h"

#include <iostream>

namespace Widgets {
MenuBar::MenuBar(QWidget * parent) :
    QMenuBar(parent), ui(new Ui::MenuBar)
{
    ui->setupUi(this);

    connect(ui->actionOpen, &QAction::triggered, this, &MenuBar::actionOpenTriggered);
    connect(ui->actionClose, &QAction::triggered, this, &MenuBar::actionCloseTriggered);
    connect(ui->actionExit, &QAction::triggered, this, &MenuBar::actionExitTriggered);
}

void MenuBar::actionOpenTriggered(bool)
{
    openFileClicked();
}

void MenuBar::actionCloseTriggered(bool)
{
    closeFileClicked();
}

void MenuBar::actionExitTriggered(bool)
{
    exitClicked();
}

MenuBar::~MenuBar()
{
    delete ui;
}

} // Widgets
