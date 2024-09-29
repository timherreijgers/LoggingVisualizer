/*
 * Copyright © 2024 Tim Herreijgers
 * Licensed using the MIT license
 */

#include "widgets/toolbar.h"

#include "ui_toolbar.h"

namespace Widgets
{
Toolbar::Toolbar(QWidget * parent) :
    QWidget(parent), m_ui(std::make_unique<Ui::Toolbar>())
{
    m_ui->setupUi(this);

    connect(m_ui->messageFilter, &QLineEdit::textChanged, this, &Toolbar::filterChanged);
    connect(m_ui->filterEnable, &QPushButton::clicked, this, &Toolbar::filterEnabledClicked);
}

Toolbar::~Toolbar() = default;

void Toolbar::setFilterEnabled(bool enabled)
{
    if (enabled)
    {
        m_ui->filterEnable->setIcon(QIcon(":/images/check_accept.png"));
        m_ui->filterEnable->setToolTip("Disable the message filter");
    }
    else
    {
        m_ui->filterEnable->setIcon(QIcon(":/images/cross_reject.png"));
        m_ui->filterEnable->setToolTip("Enable the message filter");
    }
}

} // namespace Widgets
