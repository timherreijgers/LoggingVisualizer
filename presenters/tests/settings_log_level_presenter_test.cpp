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
    std::vector<Model::LogLevelColorSettingsEntry> m_logLevelColorEntries = {
        {"INFO", {255, 255, 255, 255}, {255, 255, 255, 255}},
        {"ERROR", {255, 255, 255, 255}, {255, 255, 255, 255}}};


protected:
    void SetUp() override
    {
        ON_CALL(m_mockLogLevelWidget, connectColorSelectionChanged).WillByDefault([this](const auto& c) { m_colorSelectionChangedCallback = c; });
        ON_CALL(m_mockSettingsManager, getLogLevelColorSettings).WillByDefault(::testing::ReturnRef(m_logLevelColorEntries));
    }

    void TearDown() override
    {
        m_colorSelectionChangedCallback = nullptr;
    }
};

TEST_F(SettingsLogLevelPresenterTest, TextColorChangedInView_FirstRowChanged_PassesOnTextColorToModel)
{
    SettingsLogLevelPresenter presenter(m_mockWindowManager, m_mockLogLevelWidget, m_mockSettingsManager);

    EXPECT_CALL(m_mockSettingsManager, setLogLevelColorSettings("INFO", Types::Color{0, 0, 0, 0},
                                                                Types::Color{255, 255, 255, 255}));
    m_colorSelectionChangedCallback(0, Widgets::ColorType::TEXT, Types::Color{0, 0, 0, 0});
}

TEST_F(SettingsLogLevelPresenterTest, TextColorChangedInView_SecondRowChanged_PassesOnTextColorToModel)
{
    SettingsLogLevelPresenter presenter(m_mockWindowManager, m_mockLogLevelWidget, m_mockSettingsManager);

    EXPECT_CALL(m_mockSettingsManager, setLogLevelColorSettings("ERROR", Types::Color{0, 0, 0, 0},
                                                                Types::Color{255, 255, 255, 255}));
    m_colorSelectionChangedCallback(1, Widgets::ColorType::TEXT, Types::Color{0, 0, 0, 0});
}

TEST_F(SettingsLogLevelPresenterTest, BackgroundColorChangedInView_FirstRowChanged_PassesOnBackgroundColorToModel)
{
    SettingsLogLevelPresenter presenter(m_mockWindowManager, m_mockLogLevelWidget, m_mockSettingsManager);

    EXPECT_CALL(m_mockSettingsManager, setLogLevelColorSettings("INFO", Types::Color{255, 255, 255, 255}, Types::Color{0, 0, 0, 0}));
    m_colorSelectionChangedCallback(0, Widgets::ColorType::BACKGROUND, Types::Color{0, 0, 0, 0});
}

TEST_F(SettingsLogLevelPresenterTest, BackgroundColorChangedInView_SecondRowChanged_PassesOnBackgroundColorToModel)
{
    SettingsLogLevelPresenter presenter(m_mockWindowManager, m_mockLogLevelWidget, m_mockSettingsManager);

    EXPECT_CALL(m_mockSettingsManager, setLogLevelColorSettings("ERROR", Types::Color{255, 255, 255, 255}, Types::Color{0, 0, 0, 0}));
    m_colorSelectionChangedCallback(1, Widgets::ColorType::BACKGROUND, Types::Color{0, 0, 0, 0});
}

TEST_F(SettingsLogLevelPresenterTest, Construction_CallsSetModelOnView)
{
    EXPECT_CALL(m_mockLogLevelWidget, setModel(testing::_));

    SettingsLogLevelPresenter presenter(m_mockWindowManager, m_mockLogLevelWidget, m_mockSettingsManager);
}

} // namespace Presenters::Tests