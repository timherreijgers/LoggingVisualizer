/*
 * Copyright © 2025 Tim Herreijgers
 * Licensed using the MIT license
 */

#include "mocks/model/mock_log_data_context.hpp"
#include "mocks/widgets/mock_menu_bar.hpp"
#include "mocks/windows/mock_window_manager.hpp"
#include "presenters/menu_bar_presenter.hpp"


#include "gtest/gtest.h"

namespace Presenters::Tests
{

class MenuBarPresenterTests : public ::testing::Test
{
public:
    Windows::Mocks::MockWindowManager m_windowManager;
    Widgets::Mocks::MockMenuBar m_menubar;
    Model::Mocks::MockLogDataContext m_logDataContext;
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

// TODO: We need to have interfaces for the windows to support this test
// TEST_F(MenuBarPresenterTests, preferencesClicked_createsSettingsWindow)
// {
//     Windows::SettingsWindow settingsWindow;
//     std::function<void()> callback;
//     ON_CALL(m_menubar, connectPreferencesClicked).WillByDefault([&callback](auto c) { callback = c; });
//     ON_CALL(m_windowManager, getSettingsWindow).WillByDefault(::testing::ReturnRef(settingsWindow));
//
//     EXPECT_CALL(m_windowManager, getSettingsWindow()).Times(1);
//
//     MenuBarPresenter presenter(m_windowManager, m_menubar, m_logDataContext);
//     callback();
// }

} // namespace Presenters::Tests