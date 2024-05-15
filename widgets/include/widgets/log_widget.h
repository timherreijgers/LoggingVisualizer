/*
 * Copyright © 2024 Tim Herreijgers
 * Licensed using the MIT license
 */

#ifndef LOGGINGVISUALIZER_LOG_WIDGET_H
#define LOGGINGVISUALIZER_LOG_WIDGET_H

#include <QWidget>

namespace Widgets
{

QT_BEGIN_NAMESPACE
namespace Ui
{
class LogWidget;
}
QT_END_NAMESPACE

class LogWidget : public QWidget
{
    Q_OBJECT

public:
    explicit LogWidget(QWidget * parent = nullptr);
    ~LogWidget() override;

private:
    Ui::LogWidget * ui;
};

} // namespace Widgets

#endif // LOGGINGVISUALIZER_LOG_WIDGET_H
