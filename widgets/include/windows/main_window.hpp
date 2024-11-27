/*
 * Copyright © 2024 Tim Herreijgers
 * Licensed using the MIT license
 */

#pragma once

#include "widgets/ilog_widget.hpp"
#include "widgets/imenubar.hpp"
#include "widgets/itoolbar.hpp"

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

    [[nodiscard]] auto getMenuBar() const noexcept -> Widgets::IMenuBar&;
    [[nodiscard]] auto getLogWidget() const noexcept -> Widgets::ILogWidget&;
    [[nodiscard]] auto getToolbar() const noexcept -> Widgets::IToolbar&;

private:
    std::unique_ptr<Ui::MainWindow> m_ui;
};

} // namespace Windows
