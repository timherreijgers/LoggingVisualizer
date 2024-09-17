/*
 * Copyright © 2024 Tim Herreijgers
 * Licensed using the MIT license
 */

#pragma once

#include "types/log_entry.h"
#include "types/highlight_color_pair.h"
#include "item_models/abstract_item_model.h"

#include <QAbstractTableModel>
#include <QString>

namespace Widgets::ItemModels
{

class LogItemModel : public QAbstractTableModel
{
public:
    explicit LogItemModel(const AbstractItemModel<Types::LogEntry> & messages);

    void setHighlightColors(std::map<std::string, Types::HighlightColorPair> colorMap) noexcept;

    [[nodiscard]] auto rowCount(const QModelIndex & /*parent*/) const noexcept -> int override;
    [[nodiscard]] auto columnCount(const QModelIndex & /*parent*/) const noexcept -> int override;
    [[nodiscard]] auto data(const QModelIndex & index, int role) const -> QVariant override;

private:
    const AbstractItemModel<Types::LogEntry> & m_messages;
    std::map<std::string, Types::HighlightColorPair> m_highlightColorMap;
};

} // namespace Widgets::ItemModels