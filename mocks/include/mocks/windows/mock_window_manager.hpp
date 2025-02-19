/*
 * Copyright © 2024-2025 Tim Herreijgers
 * Licensed using the MIT license
 */

#pragma once

#include "windows/iwindow_manager.hpp"

#include <gmock/gmock.h>

namespace Windows::Mocks
{

class MockWindowManager : public IWindowManager
{
public:
    MOCK_METHOD(MainWindow&, getMainWindow, (), (override, noexcept));
    MOCK_METHOD(ISettingsWindow&, getSettingsWindow, (), (override, noexcept));
};

} // namespace Windows::Mocks