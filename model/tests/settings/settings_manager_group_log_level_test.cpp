/*
 * Copyright © 2025 Tim Herreijgers
 * Licensed using the MIT license
 */

#include "settings/settings_manager.hpp"

#include <gtest/gtest.h>

#include <memory>

namespace Model::Tests
{

class SettingsManagerGroupLogLevelTest : public ::testing::Test
{
protected:
    void SetUp() override
    {
        m_settingsManager = std::make_unique<NewSettings::SettingsManager>();
        m_logLevelsGroup = &(m_settingsManager->getSettingGroup(NewSettings::SettingsGroupId::LOG_LEVELS));
    }

    SettingsGroup* m_logLevelsGroup = nullptr;
    std::unique_ptr<NewSettings::SettingsManager> m_settingsManager;
};

TEST_F(SettingsManagerGroupLogLevelTest, LogLevelGroup_GetName_ReturnsCorrectName)
{
    ASSERT_EQ(m_logLevelsGroup->getName(), "Log Levels");
}

TEST_F(SettingsManagerGroupLogLevelTest, LogLevelGroup_GetSettings_ReturnsVectorOfSizeOne)
{
    ASSERT_EQ(m_logLevelsGroup->getSettings().size(), 1);
}

TEST_F(SettingsManagerGroupLogLevelTest, LogLevelGroup_GetSettings_FirstElementIsOfTypeLogColorSetting)
{
    ASSERT_TRUE(std::holds_alternative<LogColorSetting>(m_logLevelsGroup->getSettings().front()));
}

} // namespace Model::Tests