/*
 * Copyright © 2025 Tim Herreijgers
 * Licensed using the MIT license
 */

#pragma once

#include "model/settings/isettings_manager.hpp"

#include <gmock/gmock.h>
#include <gtest/gtest.h>

namespace Model::Mocks
{

class MockSettingsManager : public ISettingsManager
{
public:
    MOCK_METHOD(const std::vector<SettingsGroup>&, getSettingGroups, (), (const, override, noexcept));
    MOCK_METHOD(const SettingsGroup&, getSettingGroup, (SettingsGroupId), (const, override, noexcept));
    MOCK_METHOD(SettingsGroup&, getSettingGroup, (SettingsGroupId), (override, noexcept));
    MOCK_METHOD(void, saveSettings, (), (override, noexcept));
    MOCK_METHOD(Signals::scoped_connection, connectSettingsModified, (SettingsModifiedSignal::slot_type), (override));
    MOCK_METHOD(bool, isModified, (), (const, override, noexcept));
    MOCK_METHOD(void, resetModified, (), (override, noexcept));
};

} // namespace Model::Mocks