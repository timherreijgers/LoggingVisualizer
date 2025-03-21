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
class file_not_found_exception final : public std::runtime_error
{
public:
    explicit file_not_found_exception(const std::string_view fileName) :
        runtime_error(fmt::format("File {} was not found", fileName)) {}

    explicit file_not_found_exception(const std::filesystem::path& path) :
        file_not_found_exception(std::string_view{path.filename().string()}) {}
};
}; // namespace Exceptions