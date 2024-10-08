/*
 * Copyright © 2024 Tim Herreijgers
 * Licensed using the MIT license
 */

#include "log_item_model.h"

#include <QColor>

namespace Widgets::ItemModels
{

LogItemModel::LogItemModel(const AbstractItemModel<Types::LogEntry>& messages) :
    m_messages(messages)
{
}

void LogItemModel::setHighlightColors(std::map<std::string, Types::HighlightColorPair> colorMap) noexcept
{
    m_highlightColorMap = std::move(colorMap);
    layoutChanged();
}

auto LogItemModel::rowCount(const QModelIndex&) const noexcept -> int
{
    return m_messages.rowCount();
}

auto LogItemModel::columnCount(const QModelIndex&) const noexcept -> int
{
    return 3;
}

auto LogItemModel::data(const QModelIndex& index, int role) const -> QVariant
{
    if (role == Qt::ForegroundRole)
    {
        if (const auto level = std::string{m_messages.data(index.row(), 0).level}; m_highlightColorMap.contains(level))
        {
            const auto color = m_highlightColorMap.at(level).text;
            return QColor(color.red, color.green, color.blue, color.alpha);
        }

        return {};
    }

    if (role == Qt::BackgroundRole)
    {
        if (const auto level = std::string{m_messages.data(index.row(), 0).level}; m_highlightColorMap.contains(level))
        {
            const auto color = m_highlightColorMap.at(level).background;
            return QColor(color.red, color.green, color.blue, color.alpha);
        }

        return {};
    }

    if (role != Qt::DisplayRole)
    {
        return {};
    }

    switch (index.column())
    {
    case 0:
        return QString(std::string{m_messages.data(index.row(), 0).time}.c_str());
    case 1:
        return QString(std::string{m_messages.data(index.row(), 0).level}.c_str());
    case 2:
        return QString(std::string{m_messages.data(index.row(), 0).message}.c_str());
    default:
        return {};
    }
}

} // namespace Widgets::ItemModels