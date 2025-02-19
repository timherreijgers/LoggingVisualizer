/*
 * Copyright © 2025 Tim Herreijgers
 * Licensed using the MIT license
 */

#pragma once

#include "windows/isettings_window.hpp"

#include <gmock/gmock.h>

namespace Windows::Mocks
{

class MockSettingsWindow : public ISettingsWindow
{
public:
    MOCK_METHOD(Widgets::ILogLevelWidget&, getLogLevelWidget, (), (const, override, noexcept));
    MOCK_METHOD(void, showWindow, (), (override));
};

} // namespace Windows::Mocks