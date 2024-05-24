/*
 * Copyright © 2024 Tim Herreijgers
 * Licensed using the MIT license
 */

#ifndef LOGGINGVISUALIZER_LOG_WIDGET_H
#define LOGGINGVISUALIZER_LOG_WIDGET_H

#include "types/log_entry.h"


#include <qabstractitemmodel.h>
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

    void setLogMessages(const std::vector<Types::LogEntry> & messages) noexcept;

private:
    Ui::LogWidget * ui;
    std::unique_ptr<QAbstractTableModel> m_model;
};

} // namespace Widgets

#endif // LOGGINGVISUALIZER_LOG_WIDGET_H
