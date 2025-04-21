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
    SettingsObject<LogColorSettingEntryData> node{nullptr, {}};
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
    logColorSetting.addLogColorSettings("EXTRA_LEVEL", Types::Color{0xFF, 0x00, 0xFF, 0xFF},
                                        Types::Color{0, 0xFF, 0x00, 0xFF});

    ASSERT_EQ(logColorSetting.getLogColorSettingsEntries().back(),
              LogColorSettingEntry(node, LogColorSettingEntryData{6, "EXTRA_LEVEL",
                                                                  Types::Color{0xFF, 0x00, 0xFF, 0xFF},
                                                                  Types::Color{0, 0xFF, 0x00, 0xFF}}));
}


// TODO: Move the LogColorSettingEntry to a different test suite

TEST_F(SettingsManagerGroupLogLevelTest, LogColorSetting_GetLogColorSettingEntry_ThrowsExceptionIfNotValidLogLevel)
{
    const auto& logColorSetting = std::get<LogColorSetting>(m_logLevelsGroup->getSettings().front());
    ASSERT_THROW((void)logColorSetting.getLogColorSetting("NON-EXISTING LOG LEVEL"), Exceptions::LogLevelNotFoundException);
}

TEST_F(SettingsManagerGroupLogLevelTest, LogColorSetting_GetLogColorSettingEntry_ReturnsCorrectEntry)
{
    auto& logColorSetting = std::get<LogColorSetting>(m_logLevelsGroup->getSettings().front());
    logColorSetting.addLogColorSettings("EXTRA_LEVEL", Types::Color{0xFF, 0x00, 0xFF, 0xFF},
                                        Types::Color{0, 0xFF, 0x00, 0xFF});

    ASSERT_EQ(logColorSetting.getLogColorSetting("EXTRA_LEVEL"),
              LogColorSettingEntry(node, LogColorSettingEntryData{6, "EXTRA_LEVEL",
                                                                  Types::Color{0xFF, 0x00, 0xFF, 0xFF},
                                                                  Types::Color{0, 0xFF, 0x00, 0xFF}}));
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
    traceEntry.setForegroundColor(Types::Color{0xEE, 0x00, 0xAA, 0xFF});
    ASSERT_EQ(traceEntry.getForegroundColor(), (Types::Color{0xEE, 0x00, 0xAA, 0xFF}));
}

TEST_F(SettingsManagerGroupLogLevelTest, LogColorSettingEntry_SetBackgroundColor_SetsCorrectBackgroundColor)
{
    auto& logColorSetting = std::get<LogColorSetting>(m_logLevelsGroup->getSettings().front());
    auto& traceEntry = logColorSetting.getLogColorSetting("TRACE");
    traceEntry.setBackgroundColor(Types::Color{0xAA, 0x00, 0xEE, 0xFF});
    ASSERT_EQ(traceEntry.getBackgroundColor(), (Types::Color{0xAA, 0x00, 0xEE, 0xFF}));
}

TEST_F(SettingsManagerGroupLogLevelTest, LogColorSettingEntry_SetForegroundColor_SetsModifiedOnManager)
{
    auto& logColorSetting = std::get<LogColorSetting>(m_logLevelsGroup->getSettings().front());
    auto& traceEntry = logColorSetting.getLogColorSetting("TRACE");
    traceEntry.setForegroundColor(Types::Color{0xEE, 0x00, 0xAA, 0xFF});

    ASSERT_TRUE(m_settingsManager->isModified());
}

TEST_F(SettingsManagerGroupLogLevelTest, LogColorSettingEntry_SetForegroundColorToOldValue_ResetsModifiedOnManager)
{
    auto& logColorSetting = std::get<LogColorSetting>(m_logLevelsGroup->getSettings().front());
    auto& traceEntry = logColorSetting.getLogColorSetting("TRACE");
    traceEntry.setForegroundColor(Types::Color{0xEE, 0x00, 0xAA, 0xFF});
    traceEntry.setForegroundColor(Types::Color{0x00, 0x00, 0x00, 0xFF});

    ASSERT_FALSE(m_settingsManager->isModified());
}

TEST_F(SettingsManagerGroupLogLevelTest, LogColorSettingEntry_SetBackgroundColor_SetsModifiedOnManager)
{
    auto& logColorSetting = std::get<LogColorSetting>(m_logLevelsGroup->getSettings().front());
    auto& traceEntry = logColorSetting.getLogColorSetting("TRACE");
    traceEntry.setBackgroundColor(Types::Color{0xEE, 0x00, 0xAA, 0xFF});

    ASSERT_TRUE(m_settingsManager->isModified());
}

TEST_F(SettingsManagerGroupLogLevelTest, LogColorSettingEntry_SetBackgroundColorToOldValue_ResetsModifiedOnManager)
{
    auto& logColorSetting = std::get<LogColorSetting>(m_logLevelsGroup->getSettings().front());
    auto& traceEntry = logColorSetting.getLogColorSetting("TRACE");
    traceEntry.setBackgroundColor(Types::Color{0xEE, 0x00, 0xAA, 0xFF});
    traceEntry.setBackgroundColor(Types::Color{0xFF, 0xFF, 0xFF, 0xFF});

    ASSERT_FALSE(m_settingsManager->isModified());
}

TEST_F(SettingsManagerGroupLogLevelTest, LogColorSettingEntry_SetLogLevel_SetsModifiedOnManager)
{
    auto& logColorSetting = std::get<LogColorSetting>(m_logLevelsGroup->getSettings().front());
    auto& traceEntry = logColorSetting.getLogColorSetting("TRACE");
    traceEntry.setLogLevel("OTHER_LOG_LEVEL");

    ASSERT_TRUE(m_settingsManager->isModified());
}

TEST_F(SettingsManagerGroupLogLevelTest, LogColorSettingEntry_SetLogLevelToOldValue_ResetsModifiedOnManager)
{
    auto& logColorSetting = std::get<LogColorSetting>(m_logLevelsGroup->getSettings().front());
    auto& traceEntry = logColorSetting.getLogColorSetting("TRACE");
    traceEntry.setLogLevel("OTHER_LOG_LEVEL");
    traceEntry.setLogLevel("TRACE");

    ASSERT_FALSE(m_settingsManager->isModified());
}

TEST_F(SettingsManagerGroupLogLevelTest, LogColorSettingEntry_SetLogLevelIndex_SetsModifiedOnManager)
{
    auto& logColorSetting = std::get<LogColorSetting>(m_logLevelsGroup->getSettings().front());
    auto& traceEntry = logColorSetting.getLogColorSetting("TRACE");
    traceEntry.setLogLevelIndex(100);

    ASSERT_TRUE(m_settingsManager->isModified());
}

TEST_F(SettingsManagerGroupLogLevelTest, LogColorSettingEntry_SetLogLevelIndexToOldValue_ResetsModifiedOnManager)
{
    auto& logColorSetting = std::get<LogColorSetting>(m_logLevelsGroup->getSettings().front());
    auto& traceEntry = logColorSetting.getLogColorSetting("TRACE");
    traceEntry.setLogLevelIndex(100);
    traceEntry.setLogLevelIndex(0);

    ASSERT_FALSE(m_settingsManager->isModified());
}

} // namespace Model::Tests