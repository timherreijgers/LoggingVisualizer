/*
 * Copyright © 2024 Tim Herreijgers
 * Licensed using the MIT license
 */

#include "memory_mapped_file.hpp"

namespace Model::Platform
{

void MemoryMappedFile::openFile(const std::filesystem::path& path)
{
    if (m_fileData != nullptr)
    {
        closeFile();
    }

    m_fileHandle = CreateFileA(path.string().c_str(), GENERIC_READ, 0, nullptr, OPEN_EXISTING, 0, nullptr);
    auto mappedFile = CreateFileMappingA(m_fileHandle, nullptr, PAGE_READONLY, 0, 0, nullptr);
    m_fileData = static_cast<char *>(MapViewOfFile(mappedFile, FILE_MAP_READ, 0, 0, 0));

    m_memoryMappedFileParser = std::make_unique<MemoryMappedFileParser>(m_fileData);
}

void MemoryMappedFile::closeFile()
{
    UnmapViewOfFile(m_fileData);
    CloseHandle(m_fileHandle);
}

auto MemoryMappedFile::exists() const noexcept -> bool
{
    return m_fileData != nullptr;
}

auto MemoryMappedFile::hasNextLine() -> bool
{
    return m_memoryMappedFileParser->hasNextLine();
}

auto MemoryMappedFile::readNextLine() -> std::string_view
{
    return m_memoryMappedFileParser->getNextLine();
}

} // namespace Model::Platform