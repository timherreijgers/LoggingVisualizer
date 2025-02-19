/*
 * Copyright © 2024-2025 Tim Herreijgers
 * Licensed using the MIT license
 */

#pragma once

#include "windows/isettings_window.hpp"


#include <QMainWindow>

namespace Windows
{

QT_BEGIN_NAMESPACE
namespace Ui
{
class SettingsWindow;
}
QT_END_NAMESPACE

class SettingsWindow : public QMainWindow, public ISettingsWindow
{
    Q_OBJECT

public:
    explicit SettingsWindow(QWidget * parent = nullptr);
    ~SettingsWindow() override;

    [[nodiscard]] Widgets::ILogLevelWidget& getLogLevelWidget() const noexcept override;
    void showWindow() override;


private:
    std::unique_ptr<Ui::SettingsWindow> m_ui;
};

} // namespace Windows
