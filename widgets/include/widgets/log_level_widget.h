/*
 * Copyright © 2024 Tim Herreijgers
 * Licensed using the MIT license
 */

#pragma once

#include "types/color.h"

#include <QTableView>

namespace Widgets
{

enum class ColorType
{
    TEXT, BACKGROUND
};

class LogLevelWidget : public QTableView
{
    Q_OBJECT

public:
    explicit LogLevelWidget(QWidget * parent = nullptr);
    void setModel(QAbstractItemModel * model) override;

signals:
    void colorSelectionChanged(int row, Widgets::ColorType type, Types::Color color);

private slots:
    void onCellClicked(const QModelIndex& index);
};

} // namespace Widgets