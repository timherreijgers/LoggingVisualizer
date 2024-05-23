/*
 * Copyright © 2024 Tim Herreijgers
 * Licensed using the MIT license
 */

#include "model/log_data_context.h"

namespace Model
{

void LogDataContext::openFile(const std::filesystem::path &)
{
}

auto LogDataContext::subscribeToLogEntiesChanged(LogEntriesChangedListener subscriber) noexcept -> void
{
    m_logEntriesUpdatedSignal.subscribe(subscriber);
}

} // namespace Model