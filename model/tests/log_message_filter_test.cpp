/*
 * Copyright © 2024 Tim Herreijgers
 * Licensed using the MIT license
 */

#include "log_message_filter.hpp"

#include <gtest/gtest.h>

namespace Model::Tests
{

class LogMessageFilterTest : public ::testing::Test
{

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

} // namespace Model::Tests