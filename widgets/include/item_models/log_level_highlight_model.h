/*
 * Copyright © 2024 Tim Herreijgers
 * Licensed using the MIT license
 */

#pragma once

#include "types/color.h"

#include "QAbstractTableModel"

#include <vector>

namespace Widgets::ItemModels
{

class LogLevelHighlightModel : public QAbstractTableModel
{
public:
    explicit LogLevelHighlightModel() = default;

    [[nodiscard]] auto rowCount(const QModelIndex & /*parent*/) const noexcept -> int override;
    [[nodiscard]] auto columnCount(const QModelIndex & /*parent*/) const noexcept -> int override;
    [[nodiscard]] auto data(const QModelIndex & index, int role) const -> QVariant override;
    [[nodiscard]] auto headerData(int section, Qt::Orientation orientation, int role) const -> QVariant override;

    void addHighlightLevel(const std::string & level, const Types::Color & textColor, const Types::Color & backgroundColor);

private:
    struct ColorData
    {
        std::string level;
        Types::Color textColor;
        Types::Color backgroundColor;
    };

    std::vector<ColorData> m_colorData;
};

} // namespace Widgets::ItemModels