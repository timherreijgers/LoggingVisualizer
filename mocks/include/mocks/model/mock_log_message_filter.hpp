/*
 * Copyright © 2025 Tim Herreijgers
 * Licensed using the MIT license
 */

#pragma once

#include "model/ilog_message_filter.hpp"

#include <gmock/gmock.h>
#include <gtest/gtest.h>

namespace Model::Mocks
{

class MockLogMessageFilter : public ILogMessageFilter
{
public:
    MOCK_METHOD(void, setFilter, (const std::string&), (override, noexcept));
    MOCK_METHOD(void, setFilterEnabled, (bool), (override, noexcept));
    MOCK_METHOD(bool, filterEnabled, (), (const, override, noexcept));
};

} // namespace Model::Mocks