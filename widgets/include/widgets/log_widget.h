/*
 * Copyright © 2024 Tim Herreijgers
 * Licensed using the MIT license
 */

#pragma once

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
