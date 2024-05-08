/*
 * Copyright © 2022 Tim Herreijgers
 * Licensed using the MIT license
 */

#pragma once

#include <QMainWindow>

#include <memory>

namespace LoggingVisualizer
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

private:
    Ui::MainWindow* m_ui;
};

} // LoggingVisualizer
