/*
 * Copyright © 2024 Tim Herreijgers
 * Licensed using the MIT license
 */

#include "memory_mapped_file.h"

#include <Windows.h>

namespace Model::Platform::Windows
{

void MemoryMappedFile::openFile(const std::filesystem::path& path)
{
    m_fileHandle = CreateFileA(path.string().c_str(), GENERIC_READ, 0, nullptr, OPEN_EXISTING, 0, nullptr);
    // auto filesize = GetFileSize(m_fileHandle, nullptr);
    auto mappedFile = CreateFileMappingA(m_fileHandle, nullptr, PAGE_READONLY, 0, 0, nullptr);
    m_fileData = static_cast<char *>(MapViewOfFile(mappedFile, FILE_MAP_READ, 0, 0, 0));
    m_fileView = std::string_view{m_fileData};
}

void MemoryMappedFile::closeFile()
{
    UnmapViewOfFile(m_fileView.data());
    CloseHandle(m_fileHandle);
    m_lastNewLine = 0;
}

auto MemoryMappedFile::exists() const noexcept -> bool
{
    return m_fileData != nullptr;
}

auto MemoryMappedFile::hasNextLine() -> bool
{
    return m_lastNewLine < m_fileView.size();
}

// TODO: Cleanup this function
auto MemoryMappedFile::readNextLine() -> std::string
{
    const auto nextNewLine = m_fileView.find('\n', m_lastNewLine + 1) + 1;
    const auto line = nextNewLine != 0 ? std::string(m_fileView.substr(m_lastNewLine, nextNewLine - m_lastNewLine)) : std::string(m_fileView.substr(m_lastNewLine));
    m_lastNewLine = nextNewLine != 0 ? nextNewLine : m_fileView.size();
    return line;
}

} // namespace Model::Platform::Windows