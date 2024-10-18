/*
 * Copyright © 2024 Tim Herreijgers
 * Licensed using the MIT license
 */

#include "memory_mapped_file.h"

#include "exceptions/FileNotFoundException.h"

#include <cstdio>
#include <fcntl.h>
#include <sys/mman.h>
#include <unistd.h>

namespace Model::Platform
{

MemoryMappedFile::~MemoryMappedFile()
{
    MemoryMappedFile::closeFile();
}

void MemoryMappedFile::openFile(const std::filesystem::path& path)
{
    if (m_fileData != nullptr)
    {
        closeFile();
    }

    const auto fileHandle = fopen(path.string().c_str(), "r");
    if (!fileHandle)
    {
        throw Exceptions::FileNotFoundException(path);
    }

    fseek(fileHandle, 0L, SEEK_END);
    m_fileSize = ftell(fileHandle);
    fseek(fileHandle, 0L, SEEK_SET);

    m_fileHandle = open(path.string().c_str(), O_RDWR, 0);
    m_fileData = static_cast<char *>(mmap(nullptr, m_fileSize, PROT_READ, MAP_SHARED, m_fileHandle, 0));
    m_memoryMappedFileParser = std::make_unique<MemoryMappedFileParser>(m_fileData);
    fclose(fileHandle);
}

void MemoryMappedFile::closeFile()
{
    munmap(m_fileData, m_fileSize);
    close(m_fileHandle);
    m_fileHandle = 0;
}

auto MemoryMappedFile::exists() const noexcept -> bool
{
    return true;
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