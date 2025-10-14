/*
 * Copyright © 2024 Tim Herreijgers
 * Licensed using the MIT license
 */

#pragma once

#include "ifile_reader.hpp"

#include <gmock/gmock.h>

namespace Model::Mocks
{

class MockFileReader : public IFileReader
{
public:
    MOCK_METHOD(void, openFile, (const std::filesystem::path&), (override));
    MOCK_METHOD(void, closeFile, (), (override));
    MOCK_METHOD(bool, exists, (), (const, override, noexcept));
    MOCK_METHOD(bool, hasNextLine, (), (override));
    MOCK_METHOD(std::string_view, readNextLine, (), (override));
};

} // namespace Model::Mocks