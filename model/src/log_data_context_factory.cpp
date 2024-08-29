/*
 * Copyright © 2024 Tim Herreijgers
 * Licensed using the MIT license
 */

#include "log_data_context.h"

#include "model/log_data_context_factory.h"

namespace Model
{

auto LogDataContextFactory::createContext() noexcept -> std::unique_ptr<ILogDataContext>
{
    return std::make_unique<LogDataContext>();
}

} // namespace Model