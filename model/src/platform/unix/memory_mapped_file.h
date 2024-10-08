/*
 * Copyright © 2024 Tim Herreijgers
 * Licensed using the MIT license
 */

#pragma once

#include "ifile_reader.h"
#include "memory_mapped_file_parser.h"

#include <string_view>

namespace Model::Platform
{

class MemoryMappedFile : public IFileReader
{
public:
    explicit MemoryMappedFile() = default;
    ~MemoryMappedFile() override;

    void openFile(const std::filesystem::path& path) override;
    void closeFile() override;

    [[nodiscard]] auto exists() const noexcept -> bool override;
    [[nodiscard]] auto hasNextLine() -> bool override;
    [[nodiscard]] auto readNextLine() -> std::string_view override;

private:
    int m_fileHandle{0};
    size_t m_fileSize{0};

    char * m_fileData{nullptr};
    std::unique_ptr<MemoryMappedFileParser> m_memoryMappedFileParser;
};

} // namespace Model::Platform