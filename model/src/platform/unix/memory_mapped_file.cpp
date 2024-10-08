/*
 * Copyright © 2024 Tim Herreijgers
 * Licensed using the MIT license
 */

#include "memory_mapped_file.h"

#include <cstdio>
#include <sys/mman.h>
#include <fcntl.h>

namespace Model::Platform
{

MemoryMappedFile::~MemoryMappedFile()
{
    closeFile();
}

void MemoryMappedFile::openFile(const std::filesystem::path& path)
{
    auto fileHandle = fopen(path.string().c_str(), "r");
    fseek(fileHandle, 0L, SEEK_END);
    m_fileSize = ftell(fileHandle);
    fseek(fileHandle, 0L, SEEK_SET);

    m_fileHandle = open(path.string().c_str(), O_RDWR, 0);
    m_fileData = static_cast<char *>(mmap(nullptr, m_fileSize, PROT_READ, MAP_SHARED, m_fileHandle, 0));
    m_fileView = std::string_view{m_fileData};;

    m_lastNewLine = 0UL;
}

void MemoryMappedFile::closeFile()
{
    munmap(m_fileData, m_fileSize);
    m_lastNewLine = 0;
}

auto MemoryMappedFile::exists() const noexcept -> bool
{
    return true;
}

auto MemoryMappedFile::hasNextLine() -> bool
{
    return m_lastNewLine < m_fileView.size();
}

auto MemoryMappedFile::readNextLine() -> std::string
{
    const auto nextNewLine = m_fileView.find('\n', m_lastNewLine + 1) + 1;
    const auto line = nextNewLine != 0 ? std::string(m_fileView.substr(m_lastNewLine, nextNewLine - m_lastNewLine)) : std::string(m_fileView.substr(m_lastNewLine));
    m_lastNewLine = nextNewLine != 0 ? nextNewLine : m_fileView.size();
    return line;
}

} // namespace Model::Platform