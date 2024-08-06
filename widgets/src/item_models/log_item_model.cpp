/*
 * Copyright © 2024 Tim Herreijgers
 * Licensed using the MIT license
 */

#include "log_item_model.h"

#include "fmt/printf.h"

#include <QColor>

namespace Widgets::ItemModels
{

LogItemModel::LogItemModel(const std::vector<Types::LogEntry> & messages) :
    m_messages(messages)
{
}

void LogItemModel::setHighlightColors(std::map<std::string, HighlightColorData> colorMap) noexcept
{
    m_highlightColorMap = std::move(colorMap);
    layoutChanged();
}

auto LogItemModel::rowCount(const QModelIndex &) const noexcept -> int
{
    return static_cast<int>(m_messages.size());
}

auto LogItemModel::columnCount(const QModelIndex &) const noexcept -> int
{
    return 3;
}

auto LogItemModel::data(const QModelIndex & index, int role) const -> QVariant
{
    if (role == Qt::ForegroundRole)
    {
        if (const auto level = m_messages[index.row()].level; m_highlightColorMap.contains(level))
        {
            const auto color = m_highlightColorMap.at(level).first;
            return QColor(color.red, color.green, color.blue, color.alpha);
        }

        return {};
    }

    if (role == Qt::BackgroundRole)
    {
        if (const auto level = m_messages[index.row()].level; m_highlightColorMap.contains(level))
        {
            const auto color = m_highlightColorMap.at(level).second;
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
        return QString(m_messages[index.row()].time.c_str());
    case 1:
        return QString(m_messages[index.row()].level.c_str());
    case 2:
        return QString(m_messages[index.row()].message.c_str());
    default:
        return {};
    }
}

} // namespace Widgets::ItemModels