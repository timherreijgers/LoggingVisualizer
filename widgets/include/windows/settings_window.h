/*
 * Copyright © 2024 Tim Herreijgers
 * Licensed using the MIT license
 */

#ifndef SETTINGS_WINDOW_H
#define SETTINGS_WINDOW_H

#include "widgets/log_level_widget.h"


#include <QMainWindow>

namespace Windows {
QT_BEGIN_NAMESPACE
namespace Ui { class SettingsWindow; }
QT_END_NAMESPACE

class SettingsWindow : public QMainWindow {
Q_OBJECT

public:
    explicit SettingsWindow(QWidget *parent = nullptr);
    ~SettingsWindow() override;

    [[nodiscard]] Widgets::LogLevelWidget& getLogWidget() const noexcept;


private:
    Ui::SettingsWindow *ui;
};
} // Windows

#endif //SETTINGS_WINDOW_H
