/*
 * Copyright © 2025 Tim Herreijgers
 * Licensed using the MIT license
 */

#include "settings/settings_manager.hpp"

#include <gtest/gtest.h>

namespace Model::Tests
{

class SettingsManagerTest : public ::testing::Test
{
};

TEST_F(SettingsManagerTest, SettingsManager_GetSettingGroups_ReturnsVectorWithSizeOne)
{
    NewSettings::SettingsManager settingsManager;

    const auto& settingsGroups = settingsManager.getSettingGroups();

    ASSERT_EQ(settingsGroups.size(), 1);
}

TEST_F(SettingsManagerTest, SettingsManager_GetFirstSettingGroups_HasNameLogLevels)
{
    NewSettings::SettingsManager settingsManager;

    const auto& settingsGroups = settingsManager.getSettingGroups();

    ASSERT_EQ(settingsGroups[0].getName(), std::string("Log Levels"));
}

} // namespace Model::Tests