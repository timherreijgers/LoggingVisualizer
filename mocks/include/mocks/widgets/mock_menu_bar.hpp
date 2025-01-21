/*
 * Copyright © 2025 Tim Herreijgers
 * Licensed using the MIT license
 */

#pragma once

#include "widgets/imenubar.hpp"

#include <gmock/gmock.h>
#include <gtest/gtest.h>

namespace Widgets::Mocks
{

class MockMenuBar : public IMenuBar
{
public:
    MOCK_METHOD(void, connectOpenFileClicked, (const std::function<void()>&), (override));
    MOCK_METHOD(void, connectCloseFileClicked, (const std::function<void()>&), (override));
    MOCK_METHOD(void, connectPreferencesClicked, (const std::function<void()>&), (override));
    MOCK_METHOD(void, connectExitClicked, (const std::function<void()>&), (override));
    MOCK_METHOD(std::string, getFileToOpen, (), (override, noexcept));
};

} // namespace Widgets::Mocks