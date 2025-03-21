/*
 * Copyright © 2024 Tim Herreijgers
 * Licensed using the MIT license
 */

#pragma once

#include <fmt/format.h>

#include <filesystem>
#include <stdexcept>
#include <string_view>

namespace Exceptions
{
class LogLevelNotFoundException final : public std::runtime_error
{
public:
    explicit LogLevelNotFoundException(const std::string_view logLevel) :
        runtime_error(fmt::format("Debug level {} was not found", logLevel)) {}
};
}; // namespace Exceptions