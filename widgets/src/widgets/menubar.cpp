/*
 * Copyright © 2024 Tim Herreijgers
 * Licensed using the MIT license
 */

#include "widgets/menubar.h"
#include "ui_menubar.h"

#include <iostream>

namespace Widgets {
MenuBar::MenuBar(QWidget * parent) :
    QMenuBar(parent), ui(new Ui::MenuBar)
{
    ui->setupUi(this);

    connect(ui->actionOpen, &QAction::triggered, this, &MenuBar::actionOpenTriggered);
    connect(ui->actionClose, &QAction::triggered, this, &MenuBar::actionCloseTriggered);
    connect(ui->actionPreferences, &QAction::triggered, this, &MenuBar::actionPreferencesTriggered);
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

void MenuBar::actionPreferencesTriggered(bool)
{
    preferencesClicked();
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
