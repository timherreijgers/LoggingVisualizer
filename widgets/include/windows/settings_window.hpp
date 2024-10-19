/*
 * Copyright © 2024 Tim Herreijgers
 * Licensed using the MIT license
 */

#pragma once

#include "widgets/log_level_widget.hpp"


#include <QMainWindow>

namespace Windows
{

QT_BEGIN_NAMESPACE
namespace Ui
{
class SettingsWindow;
}
QT_END_NAMESPACE

class SettingsWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit SettingsWindow(QWidget * parent = nullptr);
    ~SettingsWindow() override;

    [[nodiscard]] Widgets::LogLevelWidget& getLogWidget() const noexcept;


private:
    std::unique_ptr<Ui::SettingsWindow> m_ui;
};

} // namespace Windows
