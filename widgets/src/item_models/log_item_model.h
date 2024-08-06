/*
 * Copyright © 2024 Tim Herreijgers
 * Licensed using the MIT license
 */

#pragma once

#include "types/log_entry.h"
#include "types/color.h"

#include "QAbstractTableModel"
#include "QString"

namespace Widgets::ItemModels
{

class LogItemModel : public QAbstractTableModel
{
public:
    // TODO: timher refactor this to use a struct
    using HighlightColorData = std::pair<Types::Color, Types::Color>;

    explicit LogItemModel(const std::vector<Types::LogEntry> & messages);

    void setHighlightColors(std::map<std::string, HighlightColorData> colorMap) noexcept;

    [[nodiscard]] auto rowCount(const QModelIndex & /*parent*/) const noexcept -> int override;
    [[nodiscard]] auto columnCount(const QModelIndex & /*parent*/) const noexcept -> int override;
    [[nodiscard]] auto data(const QModelIndex & index, int role) const -> QVariant override;

private:
    const std::vector<Types::LogEntry> & m_messages;
 
    std::map<std::string, HighlightColorData> m_highlightColorMap;
};

} // namespace Widgets::ItemModels