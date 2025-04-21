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
    *os << std::format("logLevelIndex: {}", entry.getLogLevelIndex())
        << std::format(", logLevel: {}", entry.getLogLevel())
        << std::format(", foregroundColor: (r:{:02X}, g:{:02X}, b:{:02X}, a:{:02X})",
            entry.getForegroundColor().red, entry.getForegroundColor().green, entry.getForegroundColor().blue, entry.getForegroundColor().alpha)
        << std::format(", backgroundColor: (r:{:02X}, g:{:02X}, b:{:02X}, a:{:02X})",
            entry.getBackgroundColor().red, entry.getBackgroundColor().green, entry.getBackgroundColor().blue, entry.getBackgroundColor().alpha);
}

} // namespace Model