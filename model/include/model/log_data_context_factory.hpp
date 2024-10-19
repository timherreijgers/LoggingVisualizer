/*
 * Copyright © 2024 Tim Herreijgers
 * Licensed using the MIT license
 */

#pragma once

#include "ilog_data_context.hpp"

namespace Model
{

class LogDataContextFactory
{
public:
    [[nodiscard]] auto static createContext() noexcept -> std::unique_ptr<ILogDataContext>;
};

} // namespace Model