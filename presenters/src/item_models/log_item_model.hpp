/*
 * Copyright © 2024 Tim Herreijgers
 * Licensed using the MIT license
 */

#pragma once

#include "model/ifiltered_log_message_view.hpp"
#include "types/log_entry.hpp"
#include "widgets/item_models/abstract_item_model.hpp"

namespace Presenters
{

class LogItemModel : public Widgets::ItemModels::AbstractItemModel<Types::LogEntry>
{
public:
    explicit LogItemModel(const Model::IFilteredLogMessageView& entries);

    [[nodiscard]] auto rowCount() const noexcept -> int override;
    [[nodiscard]] auto columnCount() const noexcept -> int override;
    [[nodiscard]] auto data(size_t row, size_t /*column*/) const -> Types::LogEntry override;

private:
    const Model::IFilteredLogMessageView& m_entries;
};

} // namespace Presenters