/*
 * Copyright © 2024 Tim Herreijgers
 * Licensed using the MIT license
 */

#include "widgets/menubar.hpp"
#include "ui_menubar.h"

#include <iostream>

namespace Widgets
{

MenuBar::MenuBar(QWidget * parent) :
    QMenuBar(parent), m_ui(std::make_unique<Ui::MenuBar>())
{
    m_ui->setupUi(this);

    connect(m_ui->actionOpen, &QAction::triggered, this, &MenuBar::actionOpenTriggered);
    connect(m_ui->actionClose, &QAction::triggered, this, &MenuBar::actionCloseTriggered);
    connect(m_ui->actionPreferences, &QAction::triggered, this, &MenuBar::actionPreferencesTriggered);
    connect(m_ui->actionExit, &QAction::triggered, this, &MenuBar::actionExitTriggered);
}

MenuBar::~MenuBar() = default;

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

} // namespace Widgets
