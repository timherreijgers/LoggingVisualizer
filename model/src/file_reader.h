/*
 * Copyright © 2024 Tim Herreijgers
 * Licensed using the MIT license
 */

#pragma once

#include <filesystem>
#include <fstream>

namespace Model
{

class FileReader
{
public:
    explicit FileReader(const std::filesystem::path& path);

    [[nodiscard]] auto exists() const noexcept -> bool;
    [[nodiscard]] auto hasNextLine() -> bool;
    [[nodiscard]] auto readNextLine() -> std::string;

private:
    std::ifstream m_stream;
};

} // namespace Model