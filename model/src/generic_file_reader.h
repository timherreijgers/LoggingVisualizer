/*
 * Copyright © 2024 Tim Herreijgers
 * Licensed using the MIT license
 */

#pragma once

#include "generic_file_reader.h"
#include "ifile_reader.h"

#include <cstdio>
#include <filesystem>

namespace Model
{

class GenericFileReader : public IFileReader
{
public:
    explicit GenericFileReader() = default;

    void setPath(const std::filesystem::path& path) noexcept override;
    [[nodiscard]] auto exists() const noexcept -> bool final;
    [[nodiscard]] auto hasNextLine() -> bool final;
    [[nodiscard]] auto readNextLine() -> std::string final;

private:
    FILE * m_file{nullptr};
    bool m_couldReadFile{true};
};

} // namespace Model