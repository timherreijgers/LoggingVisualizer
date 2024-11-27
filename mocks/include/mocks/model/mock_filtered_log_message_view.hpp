/*
 * Copyright © 2024 Tim Herreijgers
 * Licensed using the MIT license
 */

#pragma once

#include "model/ifiltered_log_message_view.hpp"

#include <gmock/gmock.h>
#include <gtest/gtest.h>

namespace Model::Mocks
{

class MockFilteredLogMessageView : public IFilteredLogMessageView
{
public:
    MOCK_METHOD(const Types::LogEntry&, get, (size_t), (const, override));
    MOCK_METHOD(size_t, size, (), (const, override, noexcept));
    MOCK_METHOD(bool, empty, (), (const, override, noexcept));

    auto operator[](size_t index) const -> const Types::LogEntry& override
    {
        return get(index);
    }
};

} // namespace Model::Mocks