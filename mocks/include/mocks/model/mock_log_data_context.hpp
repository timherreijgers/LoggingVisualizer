/*
 * Copyright © 2024-2025 Tim Herreijgers
 * Licensed using the MIT license
 */

#pragma once

#include "model/ilog_data_context.hpp"

#include <gmock/gmock.h>
#include <gtest/gtest.h>

namespace Model::Mocks
{

class MockLogDataContext : public ILogDataContext
{
public:
    MOCK_METHOD(void, openFile, (const std::filesystem::path&), (override));
    MOCK_METHOD(void, closeFile, (), (override, noexcept));
    MOCK_METHOD(ILogMessageFilter&, getLogMessageFilter, (), (override, noexcept));
    MOCK_METHOD(const IFilteredLogMessageView&, getLogMessages, (), (const, override, noexcept));
    MOCK_METHOD(is::signals::connection, connectLogMessagesChanged, (logMessageChangedSignal::slot_type), (override, noexcept));
};

} // namespace Model::Mocks