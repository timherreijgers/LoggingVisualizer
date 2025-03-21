/*
 * Copyright © 2025 Tim Herreijgers
 * Licensed using the MIT license
 */

#include "model_gtest_printers.hpp"

#include <ostream>

namespace Model
{

void PrintTo(const LogColorSettingEntry& entry, ::std::ostream * os)
{
    *os << "logLevelIndex: " << entry.getLogLevelIndex()
        << ", logLevel: " << entry.getLogLevel()
        << ", foregroundColor: " << entry.getForegroundColor()
        << ", backgroundColor: " << entry.getBackgroundColor();
}

} // namespace Model