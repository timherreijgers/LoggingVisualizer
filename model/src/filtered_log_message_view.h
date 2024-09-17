/*
 * Copyright © 2024 Tim Herreijgers
 * Licensed using the MIT license
 */

#pragma once

#include "types/log_entry.h"
#include "model/ifiltered_log_message_view.h"

#include <set>
#include <vector>

namespace Model
{

class FilteredLogMessageView : public IFilteredLogMessageView
{
public:
    explicit FilteredLogMessageView() = default;

    ~FilteredLogMessageView() override = default;

    [[nodiscard]] auto get(size_t index) const -> const Types::LogEntry & final;
    [[nodiscard]] auto operator[](size_t index) const -> const Types::LogEntry & final;
    [[nodiscard]] auto size() const noexcept -> size_t final;
    [[nodiscard]] auto empty() const noexcept -> bool final;

    void setSource(const std::vector<Types::LogEntry>* m_sourceMessages);
    void addIndex(size_t index);
    void clearIndices();

private:
    const std::vector<Types::LogEntry>* m_sourceMessages;
    std::vector<size_t> m_logIndices;
};

} // namespace Model