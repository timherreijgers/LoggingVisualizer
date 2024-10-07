/*
 * Copyright © 2024 Tim Herreijgers
 * Licensed using the MIT license
 */

#pragma once

#include <filesystem>
#include <string>

namespace Model
{

class IFileReader
{
public:
    explicit IFileReader() = default;

    virtual ~IFileReader() = default;
    IFileReader(const IFileReader& other) = delete;
    IFileReader& operator=(const IFileReader& other) = delete;
    IFileReader(IFileReader&& other) = delete;
    IFileReader& operator=(IFileReader&& other) = delete;

    virtual void openFile(const std::filesystem::path& path) = 0;
    virtual void closeFile() = 0;

    [[nodiscard]] virtual auto exists() const noexcept -> bool = 0;
    [[nodiscard]] virtual auto hasNextLine() -> bool = 0;
    [[nodiscard]] virtual auto readNextLine() -> std::string = 0;
};

} // namespace Model