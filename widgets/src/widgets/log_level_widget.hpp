/*
 * Copyright © 2024 Tim Herreijgers
 * Licensed using the MIT license
 */

#pragma once

#include "widgets/ilog_level_widget.hpp"
#include "types/color.hpp"

#include <QTableView>

namespace Widgets
{

class LogLevelWidget : public QTableView, public ILogLevelWidget
{
    Q_OBJECT

public:
    explicit LogLevelWidget(QWidget * parent = nullptr);
    void setModel(QAbstractItemModel * model) override;
    void connectColorSelectionChanged(std::function<void(int, ColorType, Types::Color)> callback) override;

private slots:
    void onCellClicked(const QModelIndex& index);

    signals:
    void colorSelectionChanged(int row, Widgets::ColorType type, Types::Color color);
};

} // namespace Widgets