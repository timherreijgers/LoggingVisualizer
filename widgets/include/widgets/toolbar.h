/*
 * Copyright © 2024 Tim Herreijgers
 * Licensed using the MIT license
 */

#pragma once

#include <QWidget>

namespace Widgets
{

QT_BEGIN_NAMESPACE
namespace Ui { class Toolbar; }
QT_END_NAMESPACE

class Toolbar : public QWidget {
Q_OBJECT

public:
    explicit Toolbar(QWidget *parent = nullptr);
    ~Toolbar() override;

private:
    Ui::Toolbar *ui;
};

} // namespace Widgets
