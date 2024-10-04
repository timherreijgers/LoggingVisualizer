/*
 * Copyright © 2024 Tim Herreijgers
 * Licensed using the MIT license
 */

#pragma once

#include "file_reader.h"
#include "ifile_reader.h"

#include <filesystem>
#include <cstdio>

namespace Model
{

class FileReader : public IFileReader
{
public:
    explicit FileReader() = default;

    void setPath(const std::filesystem::path& path) noexcept override;
    [[nodiscard]] auto exists() const noexcept -> bool final;
    [[nodiscard]] auto hasNextLine() -> bool final;
    [[nodiscard]] auto readNextLine() -> std::string final;

private:
    FILE *m_file{nullptr};
    ssize_t m_bytesRead{0};
};

} // namespace Model