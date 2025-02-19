/*
 * Copyright © 2025 Tim Herreijgers
 * Licensed using the MIT license
 */

#include "mocks/model/mock_log_data_context.hpp"
#include "mocks/widgets/mock_log_level_widget.hpp"
#include "mocks/widgets/mock_menu_bar.hpp"
#include "mocks/windows/mock_settings_window.h"
#include "mocks/windows/mock_window_manager.hpp"
#include "presenters/menu_bar_presenter.hpp"

#include "gtest/gtest.h"

namespace Presenters::Tests
{

class MenuBarPresenterTests : public ::testing::Test
{
public:
    testing::NiceMock<Windows::Mocks::MockWindowManager> m_windowManager;
    testing::NiceMock<Widgets::Mocks::MockMenuBar> m_menubar;
    testing::NiceMock<Model::Mocks::MockLogDataContext> m_logDataContext;
};

TEST_F(MenuBarPresenterTests, openFileClicked_callsOpenFileOnModel_withCorrectPath)
{
    std::function<void()> callback;
    ON_CALL(m_menubar, connectOpenFileClicked).WillByDefault([&callback](auto c) { callback = c; });
    ON_CALL(m_menubar, getFileToOpen).WillByDefault(::testing::Return(std::string{"path/to/file.txt"}));

    EXPECT_CALL(m_logDataContext, openFile(std::filesystem::path{"path/to/file.txt"}));

    MenuBarPresenter presenter(m_windowManager, m_menubar, m_logDataContext);
    callback();
}

TEST_F(MenuBarPresenterTests, closeFileClicked_callsCloseFileOnModel)
{
    std::function<void()> callback;
    ON_CALL(m_menubar, connectCloseFileClicked).WillByDefault([&callback](auto c) { callback = c; });

    EXPECT_CALL(m_logDataContext, closeFile()).Times(1);

    MenuBarPresenter presenter(m_windowManager, m_menubar, m_logDataContext);
    callback();
}

TEST_F(MenuBarPresenterTests, preferencesClicked_createsSettingsWindow)
{
    Windows::Mocks::MockSettingsWindow settingsWindow;
    Widgets::Mocks::MockLogLevelWidget logLevelWidget;

    std::function<void()> callback;
    ON_CALL(m_menubar, connectPreferencesClicked).WillByDefault([&callback](const auto& c) { callback = c; });
    ON_CALL(m_windowManager, getSettingsWindow).WillByDefault(::testing::ReturnRef(settingsWindow));
    ON_CALL(settingsWindow, getLogLevelWidget).WillByDefault(::testing::ReturnRef(logLevelWidget));

    EXPECT_CALL(m_windowManager, getSettingsWindow()).Times(1);

    MenuBarPresenter presenter(m_windowManager, m_menubar, m_logDataContext);
    callback();
}

TEST_F(MenuBarPresenterTests, preferencesClicked_showsSettingsWindow)
{
    Windows::Mocks::MockSettingsWindow settingsWindow;
    Widgets::Mocks::MockLogLevelWidget logLevelWidget;

    std::function<void()> callback;
    ON_CALL(m_menubar, connectPreferencesClicked).WillByDefault([&callback](const auto& c) { callback = c; });
    ON_CALL(m_windowManager, getSettingsWindow).WillByDefault(::testing::ReturnRef(settingsWindow));
    ON_CALL(settingsWindow, getLogLevelWidget).WillByDefault(::testing::ReturnRef(logLevelWidget));

    EXPECT_CALL(settingsWindow, showWindow()).Times(1);

    MenuBarPresenter presenter(m_windowManager, m_menubar, m_logDataContext);
    callback();
}

} // namespace Presenters::Tests