/*
 * Copyright © 2024 Tim Herreijgers
 * Licensed using the MIT license
 */

#pragma once

#include "widgets/log_widget.h"
#include "widgets/menubar.h"
#include "widgets/toolbar.h"

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
    explicit MainWindow(QWidget * parent = nullptr);
    ~MainWindow() override;
    MainWindow(MainWindow&) = delete;
    MainWindow(MainWindow&&) = delete;
    MainWindow& operator=(MainWindow&) = delete;
    MainWindow& operator=(MainWindow&&) = delete;

    [[nodiscard]] auto getMenuBar() const noexcept -> Widgets::MenuBar&;
    [[nodiscard]] auto getLogWidget() const noexcept -> Widgets::LogWidget&;
    [[nodiscard]] auto getToolbar() const noexcept -> Widgets::Toolbar&;

private:
    std::unique_ptr<Ui::MainWindow> m_ui;
};

} // namespace Windows
