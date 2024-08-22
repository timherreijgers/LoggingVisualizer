/*
 * Copyright © 2024 Tim Herreijgers
 * Licensed using the MIT license
 */

#pragma once

#include "widgets/log_widget.h"
#include "widgets/menubar.h"

#include <QMainWindow>

namespace Windows
{

QT_BEGIN_NAMESPACE
namespace Ui
{
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;
    MainWindow(MainWindow&) = delete;
    MainWindow(MainWindow&&) = delete;
    MainWindow& operator=(MainWindow&) = delete;
    MainWindow& operator=(MainWindow&&) = delete;

    [[nodiscard]] Widgets::MenuBar& getMenuBar() const noexcept;
    [[nodiscard]] Widgets::LogWidget& getLogWidget() const noexcept;

private:
    std::unique_ptr<Ui::MainWindow> m_ui;
};

} // Windows
