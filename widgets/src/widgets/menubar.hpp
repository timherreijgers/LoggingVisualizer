/*
 * Copyright © 2024 Tim Herreijgers
 * Licensed using the MIT license
 */

#pragma once

#include "widgets/imenubar.hpp"

#include <QMenuBar>

namespace Widgets
{

QT_BEGIN_NAMESPACE
namespace Ui
{
class MenuBar;
}
QT_END_NAMESPACE

class MenuBar : public QMenuBar, public IMenuBar
{
    Q_OBJECT

public:
    explicit MenuBar(QWidget * parent = nullptr);
    ~MenuBar() override;

    void connectOpenFileClicked(std::function<void()> slot) override;
    void connectCloseFileClicked(std::function<void()> slot) override;
    void connectPreferencesClicked(std::function<void()> slot) override;
    void connectExitClicked(std::function<void()> slot) override;

private slots:
    void actionOpenTriggered(bool);
    void actionCloseTriggered(bool);
    void actionPreferencesTriggered(bool);
    void actionExitTriggered(bool);

signals:
    void openFileClicked();
    void closeFileClicked();
    void preferencesClicked();
    void exitClicked();

private:
    std::unique_ptr<Ui::MenuBar> m_ui;
};

} // namespace Widgets
