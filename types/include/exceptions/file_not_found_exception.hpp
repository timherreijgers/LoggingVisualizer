/*
 * Copyright © 2024 Tim Herreijgers
 * Licensed using the MIT license
 */

#pragma once

#include <filesystem>
#include <format>
#include <stdexcept>
#include <string_view>

namespace Exceptions
{
class FileNotfoundException final : public std::runtime_error
{
public:
    explicit FileNotfoundException(const std::string_view fileName) :
        runtime_error(std::format("File {} was not found", fileName)) {}

    explicit FileNotfoundException(const std::filesystem::path& path) :
        FileNotfoundException(std::string_view{path.filename().string()}) {}
};
}; // namespace Exceptions