/*
 * Copyright © 2025 Tim Herreijgers
 * Licensed using the MIT license
 */

#include "mocks/model/mock_settings_manager.hpp"
#include "mocks/widgets/mock_log_level_widget.hpp"
#include "mocks/windows/mock_window_manager.hpp"
#include "model/settings_manager_factory.hpp"
#include "presenters/settings_log_level_presenter.hpp"

#include <gtest/gtest.h>

namespace Presenters::Tests
{

class SettingsLogLevelPresenterTest : public ::testing::Test
{
public:
    testing::NiceMock<Model::Mocks::MockSettingsManager> m_mockSettingsManager;
    testing::NiceMock<Windows::Mocks::MockWindowManager> m_mockWindowManager;
    testing::NiceMock<Widgets::Mocks::MockLogLevelWidget> m_mockLogLevelWidget;

    std::function<void(int, Widgets::ColorType, Types::Color)> m_colorSelectionChangedCallback;
    Model::SettingsNode m_node{nullptr};
    std::vector<Model::SettingsGroup> m_settingsGroups;

protected:
    void SetUp() override
    {
        m_settingsGroups.clear();
        m_settingsGroups.emplace_back("Log Levels");

        Model::LogColorSetting logColorSettings(m_node);
        logColorSettings.addLogColorSettings("INFO", {255, 255, 255, 255}, {255, 255, 255, 255});
        logColorSettings.addLogColorSettings("ERROR", {255, 255, 255, 255}, {255, 255, 255, 255});
        m_settingsGroups[0].addSetting(std::move(logColorSettings));

        ON_CALL(m_mockLogLevelWidget, connectColorSelectionChanged).WillByDefault([this](const auto& c) { m_colorSelectionChangedCallback = c; });
        ON_CALL(m_mockSettingsManager, getSettingGroups).WillByDefault(::testing::ReturnRef(m_settingsGroups));
        ON_CALL(m_mockSettingsManager, getSettingGroup(::testing::_)).WillByDefault([this](const Model::SettingsGroupId id) -> Model::SettingsGroup& {
            return m_settingsGroups[std::to_underlying(id)];
        });
    }

    void TearDown() override
    {
        m_colorSelectionChangedCallback = nullptr;
    }
};

TEST_F(SettingsLogLevelPresenterTest, TextColorChangedInView_FirstRowChanged_PassesOnTextColorToModel)
{
    SettingsLogLevelPresenter presenter(m_mockWindowManager, m_mockLogLevelWidget, m_mockSettingsManager);

    m_colorSelectionChangedCallback(0, Widgets::ColorType::TEXT, Types::Color{0, 0, 0, 0});

    const auto& logColorSettings = std::get<Model::LogColorSetting>(m_settingsGroups[0].getSettings()[0]);
    ASSERT_EQ(logColorSettings.getLogColorSettingsEntries()[0].getForegroundColor(), (Types::Color{0, 0, 0, 0}));
}

TEST_F(SettingsLogLevelPresenterTest, TextColorChangedInView_SecondRowChanged_PassesOnTextColorToModel)
{
    SettingsLogLevelPresenter presenter(m_mockWindowManager, m_mockLogLevelWidget, m_mockSettingsManager);

    m_colorSelectionChangedCallback(1, Widgets::ColorType::TEXT, Types::Color{0, 0, 0, 0});

    const auto& logColorSettings = std::get<Model::LogColorSetting>(m_settingsGroups[0].getSettings()[0]);
    ASSERT_EQ(logColorSettings.getLogColorSettingsEntries()[1].getForegroundColor(), (Types::Color{0, 0, 0, 0}));
}

TEST_F(SettingsLogLevelPresenterTest, BackgroundColorChangedInView_FirstRowChanged_PassesOnBackgroundColorToModel)
{
    SettingsLogLevelPresenter presenter(m_mockWindowManager, m_mockLogLevelWidget, m_mockSettingsManager);

    m_colorSelectionChangedCallback(0, Widgets::ColorType::BACKGROUND, Types::Color{0, 0, 0, 0});

    const auto& logColorSettings = std::get<Model::LogColorSetting>(m_settingsGroups[0].getSettings()[0]);
    ASSERT_EQ(logColorSettings.getLogColorSettingsEntries()[0].getBackgroundColor(), (Types::Color{0, 0, 0, 0}));
}

TEST_F(SettingsLogLevelPresenterTest, BackgroundColorChangedInView_SecondRowChanged_PassesOnBackgroundColorToModel)
{
    SettingsLogLevelPresenter presenter(m_mockWindowManager, m_mockLogLevelWidget, m_mockSettingsManager);

    m_colorSelectionChangedCallback(1, Widgets::ColorType::BACKGROUND, Types::Color{0, 0, 0, 0});

    const auto& logColorSettings = std::get<Model::LogColorSetting>(m_settingsGroups[0].getSettings()[0]);
    ASSERT_EQ(logColorSettings.getLogColorSettingsEntries()[1].getBackgroundColor(), (Types::Color{0, 0, 0, 0}));
}

TEST_F(SettingsLogLevelPresenterTest, Construction_CallsSetModelOnView)
{
    EXPECT_CALL(m_mockLogLevelWidget, setModel(testing::_));

    SettingsLogLevelPresenter presenter(m_mockWindowManager, m_mockLogLevelWidget, m_mockSettingsManager);
}

} // namespace Presenters::Tests