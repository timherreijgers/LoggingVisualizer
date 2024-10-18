/*
 * Copyright © 2024 Tim Herreijgers
 * Licensed using the MIT license
 */

#pragma once

#include "ifile_reader.h"

#include <string_view>
#include <Windows.h>

namespace Model::Platform
{

class MemoryMappedFile : public IFileReader
{
public:
    explicit MemoryMappedFile() = default;

    void openFile(const std::filesystem::path& path) override;
    void closeFile() override;
    [[nodiscard]] auto exists() const noexcept -> bool override;
    [[nodiscard]] auto hasNextLine() -> bool override;
    [[nodiscard]] auto readNextLine() -> std::string override;

private:
    HANDLE m_fileHandle;
    char * m_fileData{nullptr};
    std::string_view m_fileView;
    size_t m_lastNewLine = 0;
};

} // namespace Model::Platform