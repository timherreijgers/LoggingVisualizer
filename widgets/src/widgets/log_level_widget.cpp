/*
 * Copyright © 2024-2025 Tim Herreijgers
 * Licensed using the MIT license
 */

#include "log_level_widget.hpp"

#include <QApplication>
#include <QColorDialog>
#include <QHeaderView>

namespace Widgets
{

LogLevelWidget::LogLevelWidget(QWidget * parent) :
    QTableView(parent)
{
    connect(this, &QAbstractItemView::clicked, this, &LogLevelWidget::onCellClicked);
}

void LogLevelWidget::setModel(QAbstractItemModel * model)
{
    QTableView::setModel(model);

    horizontalHeader()->setStretchLastSection(false);
    horizontalHeader()->setSectionResizeMode(0, QHeaderView::Stretch);
    setColumnWidth(1, rowHeight(0) * 3);
    setColumnWidth(2, rowHeight(0) * 3);
}

void LogLevelWidget::connectColorSelectionChanged(const std::function<void(int, ColorType, Types::Color)>& slot)
{
    connect(this, &LogLevelWidget::colorSelectionChanged, slot);
}

void LogLevelWidget::onCellClicked(const QModelIndex& index)
{
    if (index.column() != 1 && index.column() != 2)
        return;

    const auto color = QColorDialog::getColor();
    if (!color.isValid())
        return;

    Types::Color typesColor{
        static_cast<uint8_t>(color.rgba() >> 16),
        static_cast<uint8_t>(color.rgba() >> 8),
        static_cast<uint8_t>(color.rgba()),
        static_cast<uint8_t>(color.rgba() >> 24)};
    colorSelectionChanged(index.row(), index.column() == 1 ? ColorType::TEXT : ColorType::BACKGROUND, typesColor);
}

} // namespace Widgets