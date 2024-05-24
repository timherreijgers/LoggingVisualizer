/*
 * Copyright (c) $originalComment.match("Copyright © (\d+)", 1, "-", "$today.year")$today.year. Tim Herreijgers
 * Licensed using the MIT license
 */
 #ifndef MENUBAR_H
#define MENUBAR_H

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
    void exitClicked();

private slots:
    void actionOpenTriggered(bool);
    void actionCloseTriggered(bool);
    void actionExitTriggered(bool);

private:
    Ui::MenuBar *ui;
};
} // Widgets

#endif //MENUBAR_H
