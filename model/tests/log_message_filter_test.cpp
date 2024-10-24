/*
 * Copyright © 2024 Tim Herreijgers
 * Licensed using the MIT license
 */

#include "log_message_filter.hpp"

#include <gmock/gmock-matchers.h>
#include <gtest/gtest.h>

namespace Model::Tests
{

class LogMessageFilterTest : public ::testing::Test
{
protected:
    [[nodiscard]] auto getLogMessages() const noexcept -> std::vector<Types::LogEntry>
    {
        return {
            {"time", "debug", "This is a debug message"},
            {"time", "error", "This is a error message"},
        };
    }
};

TEST_F(LogMessageFilterTest, FilterEnabled_WithoutFilterEnabled_ReturnsFalse)
{
    LogMessageFilter filter;
    ASSERT_FALSE(filter.filterEnabled());
}

TEST_F(LogMessageFilterTest, FilterEnabled_WithFilterEnabled_ReturnsTrue)
{
    LogMessageFilter filter;
    filter.setFilterEnabled(true);
    ASSERT_TRUE(filter.filterEnabled());
}

TEST_F(LogMessageFilterTest, SetInputMessages_CallsLogMessagesChangedSlot)
{
    LogMessageFilter filter;
    bool callbackCalled = false;
    filter.connectLogMessagesChanged([&callbackCalled]() {callbackCalled = true; });

    filter.setInputMessages(getLogMessages());
    ASSERT_TRUE(callbackCalled) << "Adding input messages should call the connected LogMessagesChanged slot";
}

TEST_F(LogMessageFilterTest, SetInputMessages_WithoutAFilter_OutputsUnfilteredMessages)
{
    LogMessageFilter filter;
    bool callbackCalled = false;
    filter.connectLogMessagesChanged([&callbackCalled]() {callbackCalled = true; });

    filter.setInputMessages(getLogMessages());

    const auto expected = getLogMessages();
    ASSERT_EQ(filter.getLogMessages().size(), expected.size());
    ASSERT_EQ(filter.getLogMessages()[0], expected[0]);
    ASSERT_EQ(filter.getLogMessages()[1], expected[1]);
}

TEST_F(LogMessageFilterTest, SetInputMessages_WithAFilterWithFilterDisabled_OutputsUnfilteredMessages)
{
    LogMessageFilter filter;
    bool callbackCalled = false;
    filter.connectLogMessagesChanged([&callbackCalled]() {callbackCalled = true; });

    filter.setInputMessages(getLogMessages());
    filter.setFilter("error");

    const auto expected = getLogMessages();
    ASSERT_EQ(filter.getLogMessages().size(), expected.size());
    ASSERT_EQ(filter.getLogMessages()[0], expected[0]);
    ASSERT_EQ(filter.getLogMessages()[1], expected[1]);
}

TEST_F(LogMessageFilterTest, SetInputMessages_WithAFilterWithFilterEnabled_OutputsUnfilteredMessages)
{
    LogMessageFilter filter;
    bool callbackCalled = false;
    filter.connectLogMessagesChanged([&callbackCalled]() {callbackCalled = true; });

    filter.setInputMessages(getLogMessages());
    filter.setFilter("error");
    filter.setFilterEnabled(true);

    const auto expected = getLogMessages();
    ASSERT_EQ(filter.getLogMessages().size(), 1);
    ASSERT_EQ(filter.getLogMessages()[0], expected[1]);
}

TEST_F(LogMessageFilterTest, SetInputMessages_WithoutAFilterWithFilterEnabled_OutputsUnfilteredMessages)
{
    LogMessageFilter filter;
    bool callbackCalled = false;
    filter.connectLogMessagesChanged([&callbackCalled]() {callbackCalled = true; });

    filter.setInputMessages(getLogMessages());
    filter.setFilterEnabled(true);

    const auto expected = getLogMessages();
    ASSERT_EQ(filter.getLogMessages().size(), expected.size());
    ASSERT_EQ(filter.getLogMessages()[0], expected[0]);
    ASSERT_EQ(filter.getLogMessages()[1], expected[1]);
}

} // namespace Model::Tests