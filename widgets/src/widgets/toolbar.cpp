/*
 * Copyright © 2024 Tim Herreijgers
 * Licensed using the MIT license
 */

#include "widgets/toolbar.h"

#include "ui_toolbar.h"

namespace Widgets
{
Toolbar::Toolbar(QWidget *parent) :
    QWidget(parent), m_ui(std::make_unique<Ui::Toolbar>())
{
    m_ui->setupUi(this);

    connect(m_ui->messageFilter, &QLineEdit::textChanged, this, &Toolbar::filterChanged);
    connect(m_ui->filterEnable, &QPushButton::clicked, this, &Toolbar::filterEnabledClicked);
}

Toolbar::~Toolbar() = default;

} // namespace Widgets
