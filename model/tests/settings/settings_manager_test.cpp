/*
 * Copyright © 2025 Tim Herreijgers
 * Licensed using the MIT license
 */

#include "settings/settings_manager.hpp"

#include <gmock/gmock.h>
#include <gtest/gtest.h>

namespace Model::Tests
{

struct CallbackMock
{
    MOCK_METHOD(void, callback, (bool));
};

class SettingsManagerTest : public ::testing::Test
{
};

TEST_F(SettingsManagerTest, SettingsManager_GetSettingGroups_ReturnsVectorWithSizeOne)
{
    SettingsManager settingsManager;

    const auto& settingsGroups = settingsManager.getSettingGroups();

    ASSERT_EQ(settingsGroups.size(), 1);
}

TEST_F(SettingsManagerTest, SettingsManager_GetFirstSettingGroups_HasNameLogLevels)
{
    SettingsManager settingsManager;

    const auto& settingsGroups = settingsManager.getSettingGroups();

    ASSERT_EQ(settingsGroups[0].getName(), std::string("Log Levels"));
}

TEST_F(SettingsManagerTest, SettingsManager_NoChanges_SettingsManagerIsNotModified)
{
    SettingsManager settingsManager;

    ASSERT_FALSE(settingsManager.isModified());
}

TEST_F(SettingsManagerTest, SettingsManager_NoChanges_ModifiedSlotNotCalled)
{
    CallbackMock callbackMock;
    EXPECT_CALL(callbackMock, callback(::testing::_)).Times(0);

    SettingsManager settingsManager;
    const auto connection = settingsManager.connectSettingsModified([&callbackMock](bool val) { callbackMock.callback(val); });
}

TEST_F(SettingsManagerTest, SettingsManager_SettingChanged_ModifiedSlotCalled)
{
    CallbackMock callbackMock;
    EXPECT_CALL(callbackMock, callback(::testing::_)).Times(1);

    SettingsManager settingsManager;
    const auto connection = settingsManager.connectSettingsModified([&callbackMock](bool val) { callbackMock.callback(val); });

    auto logColorSettingEntries = std::get<LogColorSetting>(settingsManager.getSettingGroup(SettingsGroupId::LOG_LEVELS).getSettings()[0]);
    auto logColorSettingEntry = logColorSettingEntries.getLogColorSettingsEntries()[0];
    logColorSettingEntry.setLogLevelIndex(100);
}

TEST_F(SettingsManagerTest, SettingsManager_ResetModified_ResetsModified)
{
    SettingsManager settingsManager;
    auto logColorSettingEntries = std::get<LogColorSetting>(settingsManager.getSettingGroup(SettingsGroupId::LOG_LEVELS).getSettings()[0]);
    auto logColorSettingEntry = logColorSettingEntries.getLogColorSettingsEntries()[0];
    logColorSettingEntry.setLogLevelIndex(100);

    settingsManager.resetModified();
    ASSERT_FALSE(settingsManager.isModified());
}

// TODO: Make the groups and settings non-copyable
// TODO: Add tests for loading previous saved settings from a file

} // namespace Model::Tests