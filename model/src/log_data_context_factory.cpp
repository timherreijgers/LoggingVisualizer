/*
 * Copyright © 2024 Tim Herreijgers
 * Licensed using the MIT license
 */

#include "model/log_data_context_factory.h"

#include "generic_file_reader.h"
#include "log_data_context.h"
#include "platform/memory_mapped_file.h"

namespace Model
{

auto LogDataContextFactory::createContext() noexcept -> std::unique_ptr<ILogDataContext>
{
    if constexpr (MEMORY_MAPPED_FILE_AVAILABLE)
    {
        return std::make_unique<LogDataContext>(std::make_unique<Platform::MemoryMappedFile>());
    }
    else
    {
        return std::make_unique<LogDataContext>(std::make_unique<GenericFileReader>());
    }
}

} // namespace Model