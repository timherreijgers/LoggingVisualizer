/*
 * Copyright © 2024 Tim Herreijgers
 * Licensed using the MIT license
 */

#pragma once

#include "ifile_reader.h"

#include <string_view>

namespace Model::Platform::Windows
{

class MemoryMappedFile : public IFileReader
{
public:
    explicit MemoryMappedFile() = default;

    void setPath(const std::filesystem::path& path) noexcept override;
    [[nodiscard]] auto exists() const noexcept -> bool override;
    [[nodiscard]] auto hasNextLine() -> bool override;
    [[nodiscard]] auto readNextLine() -> std::string override;

private:
    char * m_fileData{nullptr};
    std::string_view m_fileView;
    size_t m_lastNewLine = 0;
};

} // namespace Model::Platform::Windows