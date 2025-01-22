/*
 * Copyright © 2025 Tim Herreijgers
 * Licensed using the MIT license
 */

#pragma once

#include "model/isettings_manager.hpp"

#include <gmock/gmock.h>
#include <gtest/gtest.h>

namespace Model::Mocks
{

class MockSettingsManager : public ISettingsManager
{
public:
    MOCK_METHOD(void, setLogLevelColorSettings, (std::string, Types::Color, Types::Color), (override));
    MOCK_METHOD(const std::vector<LogLevelColorSettingsEntry>&, getLogLevelColorSettings, (), (override, noexcept));
    MOCK_METHOD(void, saveSettings, (), (override));
    MOCK_METHOD(Signals::connection, connectSettingsChangedSignal, (SettingsChangedSignal::slot_type), (override));
};

} // namespace Model::Mocks