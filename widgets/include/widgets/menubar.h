/*
 * Copyright © 2024 Tim Herreijgers
 * Licensed using the MIT license
 */

#pragma once

#include <QMenuBar>

namespace Widgets {
QT_BEGIN_NAMESPACE
namespace Ui { class MenuBar; }
QT_END_NAMESPACE

class MenuBar : public QMenuBar {
Q_OBJECT

public:
    explicit MenuBar(QWidget *parent = nullptr);
    ~MenuBar() override;

signals:
    void openFileClicked();
    void closeFileClicked();
    void preferencesClicked();
    void exitClicked();

private slots:
    void actionOpenTriggered(bool);
    void actionCloseTriggered(bool);
    void actionPreferencesTriggered(bool);
    void actionExitTriggered(bool);

private:
    Ui::MenuBar *ui;
};
} // Widgets
