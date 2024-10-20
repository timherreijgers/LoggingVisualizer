/*
 * Copyright © 2024 Tim Herreijgers
 * Licensed using the MIT license
 */

#include "memory_mapped_file_parser.hpp"

#include <gtest/gtest.h>

#include <memory>

namespace Model::Tests
{

class MemoryMappedFileParserTest : public ::testing::Test
{
protected:
    MemoryMappedFileParserTest()
    {
        m_fileDataWithoutEndingNewline =
            "This is the first line\n"
            "This is the second line\n"
            "This is the third line";

        m_fileDataWithEndingNewline =
            "This is the first line\n"
            "This is the second line\n"
            "This is the third line\n";
    }

    std::string_view m_fileDataWithoutEndingNewline;
    std::string_view m_fileDataWithEndingNewline;
};

TEST_F(MemoryMappedFileParserTest, GetNextLine_WithoutEndingNewLine_ReturnsNextLine)
{
    MemoryMappedFileParser parser{m_fileDataWithoutEndingNewline};
    ASSERT_EQ(parser.getNextLine(), "This is the first line");
    ASSERT_EQ(parser.getNextLine(), "This is the second line");
    ASSERT_EQ(parser.getNextLine(), "This is the third line");
}

TEST_F(MemoryMappedFileParserTest, GetNextLine_WithEndingNewLine_ReturnsNextLine)
{
    MemoryMappedFileParser parser{m_fileDataWithEndingNewline};
    ASSERT_EQ(parser.getNextLine(), "This is the first line");
    ASSERT_EQ(parser.getNextLine(), "This is the second line");
    ASSERT_EQ(parser.getNextLine(), "This is the third line");
}

TEST_F(MemoryMappedFileParserTest, HasNextLine_WithoutEndingNewLine_ReturnsWhetherHasNextLine)
{
    MemoryMappedFileParser parser{m_fileDataWithoutEndingNewline};

    ASSERT_TRUE(parser.hasNextLine());
    [[maybe_unused]] const auto _0 = parser.getNextLine();

    ASSERT_TRUE(parser.hasNextLine());
    [[maybe_unused]] const auto _1 = parser.getNextLine();

    ASSERT_TRUE(parser.hasNextLine());
    [[maybe_unused]] const auto _2 = parser.getNextLine();

    ASSERT_FALSE(parser.hasNextLine());
}

TEST_F(MemoryMappedFileParserTest, HasNextLine_WithEndingNewLine_ReturnsWhetherHasNextLine)
{
    MemoryMappedFileParser parser{m_fileDataWithEndingNewline};

    ASSERT_TRUE(parser.hasNextLine());
    [[maybe_unused]] const auto _0 = parser.getNextLine();

    ASSERT_TRUE(parser.hasNextLine());
    [[maybe_unused]] const auto _1 = parser.getNextLine();

    ASSERT_TRUE(parser.hasNextLine());
    [[maybe_unused]] const auto _2 = parser.getNextLine();

    ASSERT_FALSE(parser.hasNextLine());
}

} // namespace Model::Tests