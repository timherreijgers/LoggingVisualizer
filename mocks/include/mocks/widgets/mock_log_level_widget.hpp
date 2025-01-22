/*
 * Copyright © 2025 Tim Herreijgers
 * Licensed using the MIT license
 */

#pragma once

#include "widgets/ilog_level_widget.hpp"

#include <gmock/gmock.h>
#include <gtest/gtest.h>

namespace Widgets::Mocks
{

class MockLogLevelWidget : public ILogLevelWidget
{
public:
    MOCK_METHOD(void, setModel, (QAbstractItemModel *), (override));
    MOCK_METHOD(void, connectColorSelectionChanged, (const std::function<void(int, ColorType, Types::Color)>&), (override));
};

} // namespace Widgets::Mocks