/*
 * Copyright © 2024 Tim Herreijgers
 * Licensed using the MIT license
 */

#pragma once

#include "types/log_entry.h"

#include <vector>

namespace Model
{

class LogDataContext
{
public:
    explicit LogDataContext() = default;

    [[nodiscard]] auto getLogEntries() const noexcept -> const std::vector<Types::LogEntry> &;
};

} // namespace Model