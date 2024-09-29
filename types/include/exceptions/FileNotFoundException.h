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
class FileNotFoundException final : public std::runtime_error
{
public:
    explicit FileNotFoundException(const std::string_view fileName) :
        runtime_error(fmt::format("File {} was not found", fileName)) {}

    explicit FileNotFoundException(const std::filesystem::path& path) :
        FileNotFoundException(std::string_view{path.filename().string()}) {}
};
}; // namespace Exceptions