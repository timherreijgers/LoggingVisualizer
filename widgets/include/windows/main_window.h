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

namespace Ui { class MainWindow; }

class MainWindow : public QMainWindow {
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
    Ui::MainWindow* m_ui;
};

} // Windows
