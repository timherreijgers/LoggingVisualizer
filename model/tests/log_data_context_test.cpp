/*
 * Copyright © 2024 Tim Herreijgers
 * Licensed using the MIT license
 */

#include "exceptions/FileNotFoundException.hpp"
#include "log_data_context.hpp"
#include "mocks/mock_file_reader.h"

#include <gtest/gtest.h>

namespace Model::Tests
{

class LogDataContextTest : public ::testing::Test
{
protected:
    void SetUp() override
    {
        m_fileReader = std::make_unique<::testing::NiceMock<Mocks::MockFileReader>>();
    }

    void setupMockForFileSimulation()
    {
        const auto fileReaderMock = m_fileReader.get();

        ON_CALL(*fileReaderMock, exists()).WillByDefault(::testing::Return(true));
        ON_CALL(*fileReaderMock, hasNextLine()).WillByDefault([this]() {
            return m_index < m_lines.size();
        });
        ON_CALL(*fileReaderMock, readNextLine()).WillByDefault([this]() -> std::string_view {
            return m_lines[m_index++];
        });
    }

    std::unique_ptr<::testing::NiceMock<Mocks::MockFileReader>> m_fileReader;
    std::vector<std::string> m_lines = {"[time][debug]This is a debug message", "[time][error]This is a error message"};
    std::vector<Types::LogEntry> m_entries = {
        {"time", "debug", "This is a debug message"},
        {"time", "error", "This is a error message"}};
    size_t m_index = 0;
};

TEST_F(LogDataContextTest, OpenFile_FileReaderReturnsFalse_ThrowsFileNotFoundException)
{
    const auto fileReaderMock = m_fileReader.get();
    ON_CALL(*fileReaderMock, exists()).WillByDefault(::testing::Return(false));
    LogDataContext context{std::move(m_fileReader)};

    ASSERT_THROW(context.openFile("/folder/test_file.log"), Exceptions::FileNotFoundException);
}

TEST_F(LogDataContextTest, OpenFile_callsFileReaderOpenFile_WithCorrectPath)
{
    const auto fileReaderMock = m_fileReader.get();
    ON_CALL(*fileReaderMock, exists()).WillByDefault(::testing::Return(true));
    LogDataContext context{std::move(m_fileReader)};

    EXPECT_CALL(*fileReaderMock, openFile(std::filesystem::path{"/folder/test_file.log"})).Times(1);
    context.openFile("/folder/test_file.log");
}

TEST_F(LogDataContextTest, OpenFile_FileReaderHasNoLines_ReturnsNoLogEntries)
{
    const auto fileReaderMock = m_fileReader.get();
    ON_CALL(*fileReaderMock, exists()).WillByDefault(::testing::Return(true));
    LogDataContext context{std::move(m_fileReader)};

    context.openFile("/folder/test_file.log");
    ASSERT_EQ(context.getLogMessages().size(), 0);
}

TEST_F(LogDataContextTest, OpenFile_FileReaderHasTwoLines_ReturnsTwoCorrectLogLines)
{
    setupMockForFileSimulation();

    LogDataContext context{std::move(m_fileReader)};

    context.openFile("/folder/test_file.log");
    ASSERT_EQ(context.getLogMessages().size(), 2);
    ASSERT_EQ(context.getLogMessages().get(0), m_entries[0]);
    ASSERT_EQ(context.getLogMessages().get(1), m_entries[1]);
}

TEST_F(LogDataContextTest, OpenFile_FileReaderHasTwoLines_WithFilter_ReturnsCorrectLogLines)
{
    setupMockForFileSimulation();

    LogDataContext context{std::move(m_fileReader)};
    context.getLogMessageFilter().setFilterEnabled(true);
    context.getLogMessageFilter().setFilter("error");

    context.openFile("/folder/test_file.log");
    ASSERT_EQ(context.getLogMessages().size(), 1);
    ASSERT_EQ(context.getLogMessages().get(0), m_entries[1]);
}

TEST_F(LogDataContextTest, close_callsCloseOnFileReader)
{
    const auto fileReaderMock = m_fileReader.get();
    ON_CALL(*fileReaderMock, exists()).WillByDefault(::testing::Return(true));

    LogDataContext context{std::move(m_fileReader)};
    context.openFile("/folder/test_file.log");

    EXPECT_CALL(*fileReaderMock, closeFile()).Times(1);
    context.closeFile();
}

TEST_F(LogDataContextTest, close_WithInputMessages_clearsMessages)
{
    setupMockForFileSimulation();

    LogDataContext context{std::move(m_fileReader)};
    context.openFile("/folder/test_file.log");
    context.closeFile();

    ASSERT_EQ(context.getLogMessages().size(), 0);
}

} // namespace Model::Tests