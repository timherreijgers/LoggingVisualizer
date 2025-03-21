/*
 * Copyright © 2025 Tim Herreijgers
 * Licensed using the MIT license
 */

#include "exceptions/log_level_not_found_exception.hpp"
#include "model_gtest_printers.hpp"
#include "settings/settings_manager.hpp"

#include <gtest/gtest.h>

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

    SettingsGroup * m_logLevelsGroup = nullptr;
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

TEST_F(SettingsManagerGroupLogLevelTest, LogColorSetting_GetLogColorSettingEntries_ReturnsSixSettings)
{
    const auto& logColorSetting = std::get<LogColorSetting>(m_logLevelsGroup->getSettings().front());
    ASSERT_EQ(logColorSetting.getLogColorSettingsEntries().size(), 6);
}

TEST_F(SettingsManagerGroupLogLevelTest, LogColorSetting_AddLogColorSettings_AddsLogColorSetting)
{
    auto& logColorSetting = std::get<LogColorSetting>(m_logLevelsGroup->getSettings().front());
    logColorSetting.addLogColorSettings("EXTRA_LEVEL", "#FF00FF", "#00FF00");

    ASSERT_EQ(logColorSetting.getLogColorSettingsEntries().back(),
              LogColorSettingEntry(6, "EXTRA_LEVEL", "#FF00FF", "#00FF00"));
}

TEST_F(SettingsManagerGroupLogLevelTest, LogColorSetting_GetLogColorSettingEntry_ThrowsExceptionIfNotValidLogLevel)
{
    const auto& logColorSetting = std::get<LogColorSetting>(m_logLevelsGroup->getSettings().front());
    ASSERT_THROW((void)logColorSetting.getLogColorSetting("NON-EXISTING LOG LEVEL"), Exceptions::LogLevelNotFoundException);
}

TEST_F(SettingsManagerGroupLogLevelTest, LogColorSetting_GetLogColorSettingEntry_ReturnsCorrectEntry)
{
    auto& logColorSetting = std::get<LogColorSetting>(m_logLevelsGroup->getSettings().front());
    logColorSetting.addLogColorSettings("EXTRA_LEVEL", "#FF00FF", "#00FF00");

    ASSERT_EQ(logColorSetting.getLogColorSetting("EXTRA_LEVEL"),
              LogColorSettingEntry(6, "EXTRA_LEVEL", "#FF00FF", "#00FF00"));
}

TEST_F(SettingsManagerGroupLogLevelTest, LogColorSettingEntry_SetLogLevelIndex_SetsCorrectLogLevelIndex)
{
    auto& logColorSetting = std::get<LogColorSetting>(m_logLevelsGroup->getSettings().front());
    auto& traceEntry = logColorSetting.getLogColorSetting("TRACE");
    traceEntry.setLogLevelIndex(100);
    ASSERT_EQ(traceEntry.getLogLevelIndex(), 100);
}

TEST_F(SettingsManagerGroupLogLevelTest, LogColorSettingEntry_SetLogLevel_SetsCorrectLogLevel)
{
    auto& logColorSetting = std::get<LogColorSetting>(m_logLevelsGroup->getSettings().front());
    auto& traceEntry = logColorSetting.getLogColorSetting("TRACE");
    traceEntry.setLogLevel("Changed log level");
    ASSERT_EQ(traceEntry.getLogLevel(), "Changed log level");
}

TEST_F(SettingsManagerGroupLogLevelTest, LogColorSettingEntry_SetForegroundColor_SetsCorrectForegroundColor)
{
    auto& logColorSetting = std::get<LogColorSetting>(m_logLevelsGroup->getSettings().front());
    auto& traceEntry = logColorSetting.getLogColorSetting("TRACE");
    traceEntry.setForegroundColor("#EE00AA");
    ASSERT_EQ(traceEntry.getForegroundColor(), "#EE00AA");
}

TEST_F(SettingsManagerGroupLogLevelTest, LogColorSettingEntry_SetBackgroundColor_SetsCorrectBackgroundColor)
{
    auto& logColorSetting = std::get<LogColorSetting>(m_logLevelsGroup->getSettings().front());
    auto& traceEntry = logColorSetting.getLogColorSetting("TRACE");
    traceEntry.setBackgroundColor("#AA00EE");
    ASSERT_EQ(traceEntry.getBackgroundColor(), "#AA00EE");
}

// TODO: Move the LogColorSettingEntry to a different test suite
// TODO: Add tests for modified

} // namespace Model::Tests