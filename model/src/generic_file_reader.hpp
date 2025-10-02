/*
 * Copyright © 2024 Tim Herreijgers
 * Licensed using the MIT license
 */

#pragma once

#include "generic_file_reader.hpp"
#include "ifile_reader.hpp"

#include <filesystem>
#include <vector>

namespace Model
{

void fileDeleter(std::FILE * file)
{
    std::fclose(file);
}

class GenericFileReader : public IFileReader
{
public:
    explicit GenericFileReader();

    void openFile(const std::filesystem::path& path) override;
    void closeFile() override;
    [[nodiscard]] auto exists() const noexcept -> bool final;
    [[nodiscard]] auto hasNextLine() -> bool final;
    [[nodiscard]] auto readNextLine() -> std::string_view final;

private:
    std::unique_ptr<std::FILE, decltype(&fileDeleter)> m_file;
    std::vector<std::string> m_lines;

    bool m_couldReadFile{true};
    size_t m_index{0};
};

} // namespace Model