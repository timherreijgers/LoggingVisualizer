/*
 * Copyright © 2024 Tim Herreijgers
 * Licensed using the MIT license
 */

#include "exceptions/FileNotFoundException.hpp"
#include "filtered_log_message_view.hpp"

#include <gtest/gtest.h>

namespace Model::Tests
{

class FilteredLogMessageViewTest : public ::testing::Test
{
protected:
    [[nodiscard]] auto generateLogEntries() const noexcept -> std::vector<Types::LogEntry>
    {
        return {
            {"time", "debug", "message1"},
            {"time", "error", "message2"},
        };
    }
};

TEST_F(FilteredLogMessageViewTest, Size_WithoutSourceAdded_ReturnsZero)
{
    FilteredLogMessageView view;
    ASSERT_EQ(view.size(), 0);
}

TEST_F(FilteredLogMessageViewTest, Size_WithSourceAddedWithoutIndices_ReturnsZero)
{
    FilteredLogMessageView view;
    const auto entries = generateLogEntries();
    view.setSource(&entries);

    ASSERT_EQ(view.size(), 0);
}

TEST_F(FilteredLogMessageViewTest, Size_WithSourceAddedWithIndices_ReturnsCorrectSize)
{
    FilteredLogMessageView view;
    const auto entries = generateLogEntries();
    view.setSource(&entries);

    view.addIndex(0);
    ASSERT_EQ(view.size(), 1);

    view.addIndex(1);
    ASSERT_EQ(view.size(), 2);
}

TEST_F(FilteredLogMessageViewTest, Empty_WithoutSourceAdded_ReturnsTrue)
{
    FilteredLogMessageView view;
    ASSERT_TRUE(view.empty());
}

TEST_F(FilteredLogMessageViewTest, Empty_WithSourceAddedWithoutIndices_ReturnsTrue)
{
    FilteredLogMessageView view;
    const auto entries = generateLogEntries();
    view.setSource(&entries);

    ASSERT_TRUE(view.empty());
}

TEST_F(FilteredLogMessageViewTest, Empty_WithSourceAddedWithIndices_ReturnsFalse)
{
    FilteredLogMessageView view;
    const auto entries = generateLogEntries();
    view.setSource(&entries);

    view.addIndex(0);
    ASSERT_FALSE(view.empty());
}

TEST_F(FilteredLogMessageViewTest, Get_WithoutSource_ThrowsException)
{
    FilteredLogMessageView view;
    ASSERT_THROW((void)view.get(0), std::runtime_error);
}

TEST_F(FilteredLogMessageViewTest, Get_WithSourceWithoutIndices_ThrowsOutOfRangeException)
{
    FilteredLogMessageView view;
    const auto entries = generateLogEntries();
    view.setSource(&entries);
    ASSERT_THROW((void)view.get(0), std::out_of_range);
}

TEST_F(FilteredLogMessageViewTest, Get_WithSourceWithIndices_ReturnsCorrectLine)
{
    FilteredLogMessageView view;
    const auto entries = generateLogEntries();
    view.setSource(&entries);
    view.addIndex(1);

    constexpr auto expected = Types::LogEntry{"time", "error", "message2"};
    ASSERT_EQ(view.get(0), expected);
}

TEST_F(FilteredLogMessageViewTest, Get_WithSourceWithIndices_ReturnsOutOfRange)
{
    FilteredLogMessageView view;
    const auto entries = generateLogEntries();
    view.setSource(&entries);
    view.addIndex(1);

    ASSERT_THROW((void)view.get(1), std::out_of_range);
}

TEST_F(FilteredLogMessageViewTest, Operator_WithoutSource_ThrowsException)
{
    FilteredLogMessageView view;
    ASSERT_THROW((void)view[0], std::runtime_error);
}

TEST_F(FilteredLogMessageViewTest, Operator_WithSourceWithoutIndices_ThrowsOutOfRangeException)
{
    FilteredLogMessageView view;
    const auto entries = generateLogEntries();
    view.setSource(&entries);
    ASSERT_THROW((void)view[0], std::out_of_range);
}

TEST_F(FilteredLogMessageViewTest, Operator_WithSourceWithIndices_ReturnsCorrectLine)
{
    FilteredLogMessageView view;
    const auto entries = generateLogEntries();
    view.setSource(&entries);
    view.addIndex(1);

    constexpr auto expected = Types::LogEntry{"time", "error", "message2"};
    ASSERT_EQ(view[0], expected);
}

TEST_F(FilteredLogMessageViewTest, Operator_withSourceWithIndices_ReturnsOutOfRange)
{
    FilteredLogMessageView view;
    const auto entries = generateLogEntries();
    view.setSource(&entries);
    view.addIndex(1);

    ASSERT_THROW((void)view[1], std::out_of_range);
}

} // namespace Model::Tests