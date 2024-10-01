/*
 * Copyright (c) $originalComment.match("Copyright © (\d+)", 1, "-", "$today.year")$today.year. Tim Herreijgers
 * Licensed using the MIT license
 */
 
#pragma once

#include <string>
#include <filesystem>

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

    virtual void setPath(const std::filesystem::path& path) noexcept = 0;
    [[nodiscard]] virtual auto exists() const noexcept -> bool = 0;
    [[nodiscard]] virtual auto hasNextLine() -> bool = 0;
    [[nodiscard]] virtual auto readNextLine() -> std::string = 0;
};

} // namespace Model