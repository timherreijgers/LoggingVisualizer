/*
 * Copyright © 2024 Tim Herreijgers
 * Licensed using the MIT license
 */

#include "model/log_data_context_factory.h"

#include "file_reader.h"
#include "log_data_context.h"

namespace Model
{

auto LogDataContextFactory::createContext() noexcept -> std::unique_ptr<ILogDataContext>
{
    return std::make_unique<LogDataContext>(std::make_unique<FileReader>());
}

} // namespace Model