/*
 * Copyright © 2024 Tim Herreijgers
 * Licensed using the MIT license
 */

#include "item_models/log_level_highlight_model.h"

#include "qcolor.h"

namespace Widgets::ItemModels
{

auto LogLevelHighlightModel::rowCount(const QModelIndex &) const noexcept -> int
{
    return static_cast<int>(m_colorData.size());
}

auto LogLevelHighlightModel::columnCount(const QModelIndex &) const noexcept -> int
{
    return 3;
}

auto LogLevelHighlightModel::data(const QModelIndex & index, int role) const -> QVariant
{
    if (role == Qt::BackgroundRole && index.column() != 0)
    {
        const auto & colorData = m_colorData[index.row()];

        const auto level = colorData.level;
        const auto color = index.column() == 1 ? colorData.textColor : colorData.backgroundColor;
        return QColor(color.red, color.green, color.blue, color.alpha);
    }

    if (role != Qt::DisplayRole)
        return {};

    if (index.column() == 0)
        return QString::fromStdString(m_colorData[index.row()].level);

    return {};
}

auto LogLevelHighlightModel::headerData(int section, Qt::Orientation orientation, int role) const -> QVariant
{
    if (role != Qt::DisplayRole)
        return {};

    if (orientation != Qt::Horizontal)
        return {};

    switch (section)
    {
    case 0:
        return "Level";
    case 1:
        return "Text";
    case 2:
        return "background";
    default:
        return {};
    }
}

void LogLevelHighlightModel::addHighlightLevel(const std::string & level, const Types::Color & textColor, const Types::Color & backgroundColor)
{
    m_colorData.emplace_back(level, textColor, backgroundColor);
    // This should force a complete update for the whole view
    dataChanged(index(0, 0), index(2, static_cast<int>(m_colorData.size())));
}

} // namespace Widgets::ItemModels