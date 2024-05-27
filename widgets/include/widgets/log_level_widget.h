/*
 * Copyright © 2024 Tim Herreijgers
 * Licensed using the MIT license
 */

#pragma once

#include <QTableView>

namespace Widgets
{

class LogLevelWidget : public QTableView
{
    Q_OBJECT

public:
    explicit LogLevelWidget(QWidget * parent = nullptr);
    void setModel(QAbstractItemModel * model) override;

private slots:
    void onCellClicked(const QModelIndex& index);
};

} // namespace Widgets