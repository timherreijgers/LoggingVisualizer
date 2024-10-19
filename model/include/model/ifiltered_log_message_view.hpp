/*
 * Copyright © 2024 Tim Herreijgers
 * Licensed using the MIT license
 */

#pragma once

#include "types/log_entry.hpp"

namespace Model
{

class IFilteredLogMessageView
{
public:
    explicit IFilteredLogMessageView() = default;

    virtual ~IFilteredLogMessageView() = default;
    IFilteredLogMessageView(const IFilteredLogMessageView& other) = delete;
    IFilteredLogMessageView& operator=(const IFilteredLogMessageView& other) = delete;
    IFilteredLogMessageView(IFilteredLogMessageView&& other) = delete;
    IFilteredLogMessageView& operator=(IFilteredLogMessageView&& other) = delete;

    [[nodiscard]] virtual auto get(size_t index) const -> const Types::LogEntry& = 0;
    [[nodiscard]] virtual auto operator[](size_t index) const -> const Types::LogEntry& = 0;
    [[nodiscard]] virtual auto size() const noexcept -> size_t = 0;
    [[nodiscard]] virtual auto empty() const noexcept -> bool = 0;
};

} // namespace Model