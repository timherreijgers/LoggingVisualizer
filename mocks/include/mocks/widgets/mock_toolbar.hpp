/*
 * Copyright © 2025 Tim Herreijgers
 * Licensed using the MIT license
 */

#pragma once

#include <widgets/itoolbar.hpp>

#include <gmock/gmock.h>
#include <gtest/gtest.h>

namespace Widgets::Mocks
{

class MockToolbar : public IToolbar
{
public:
    MOCK_METHOD(void, setFilterEnabled, (bool), (override));
    MOCK_METHOD(void, connectFilterChanged, (std::function<void(const std::string&)>), (override));
    MOCK_METHOD(void, connectFilterEnabledClicked, (std::function<void()>), (override));
};

} // namespace Widgets::Mocks