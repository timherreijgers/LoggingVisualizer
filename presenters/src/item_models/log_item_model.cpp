/*
 * Copyright © 2024 Tim Herreijgers
 * Licensed using the MIT license
 */

#include "log_item_model.h"

namespace Presenters
{

LogItemModel::LogItemModel(const Model::IFilteredLogMessageView& entries) :
    m_entries(entries) {}

auto LogItemModel::rowCount() const noexcept -> int
{
    return static_cast<int>(m_entries.size());
}

auto LogItemModel::columnCount() const noexcept -> int
{
    return 1;
}

auto LogItemModel::data(size_t row, size_t) const -> Types::LogEntry
{
    return m_entries[row];
}

} // namespace Presenters