/*
 * Copyright © 2024-2025 Tim Herreijgers
 * Licensed using the MIT license
 */

#pragma once

#include "widgets/ilog_widget.hpp"

#include <gmock/gmock.h>
#include <gtest/gtest.h>

namespace Widgets::Mocks
{

class MockLogWidget : public ILogWidget
{
public:
    MOCK_METHOD(void, setLogMessages, (const Widgets::ItemModels::AbstractItemModel<Types::LogEntry>&), (override, noexcept));
    MOCK_METHOD(void, clearLogMessages, (), (override, noexcept));
    MOCK_METHOD(void, setHighlightColors, ((std::map<std::string, Types::HighlightColorPair>)), (override, noexcept));
    MOCK_METHOD(void, connectOnFileDropped, (const std::function<void(std::string_view)>&), (override));
};

} // namespace Widgets::Mocks