/*
 * Copyright © 2025 Tim Herreijgers
 * Licensed using the MIT license
 */

#include "mocks/model/mock_log_data_context.hpp"
#include "mocks/model/mock_log_message_filter.hpp"
#include "mocks/widgets/mock_toolbar.hpp"
#include "mocks/windows/mock_window_manager.hpp"
#include "presenters/toolbar_presenter.hpp"

#include <gmock/gmock.h>
#include <gtest/gtest.h>

namespace Presenters::Tests
{

class ToolbarPresenterTest : public ::testing::Test
{
public:
    testing::NiceMock<Windows::Mocks::MockWindowManager> m_mockWindowManager;
    testing::NiceMock<Model::Mocks::MockLogDataContext> m_mockLogDataContext;
    testing::NiceMock<Model::Mocks::MockLogMessageFilter> m_logMessageFilter;
    testing::NiceMock<Widgets::Mocks::MockToolbar> m_mockToolbar;

    std::function<void(const std::string&)> m_filterInputChanged;
    std::function<void()> m_filterEnabledClicked;


protected:
    void SetUp() override
    {
        ON_CALL(m_mockToolbar, connectFilterChanged).WillByDefault([this](const auto& func) { m_filterInputChanged = func; });
        ON_CALL(m_mockToolbar, connectFilterEnabledClicked).WillByDefault([this](const auto& func) { m_filterEnabledClicked = func; });

        ON_CALL(m_mockLogDataContext, getLogMessageFilter).WillByDefault([&]() -> Model::ILogMessageFilter& { return m_logMessageFilter; });
    }

    void TearDown() override
    {
        m_filterInputChanged = nullptr;
    }
};

TEST_F(ToolbarPresenterTest, FilterChangedInView_ChangesFilterInModel)
{
    ToolbarPresenter toolbarPresenter(m_mockWindowManager, m_mockToolbar, m_mockLogDataContext);

    EXPECT_CALL(m_logMessageFilter, setFilter("Filter123")).Times(1);
    m_filterInputChanged("Filter123");
}

TEST_F(ToolbarPresenterTest, FilterEnableClickedInView_EnablesFilterInModelIfDisabled)
{
    ToolbarPresenter toolbarPresenter(m_mockWindowManager, m_mockToolbar, m_mockLogDataContext);

    ON_CALL(m_logMessageFilter, filterEnabled).WillByDefault(testing::Return(false));
    EXPECT_CALL(m_logMessageFilter, setFilterEnabled(true)).Times(1);

    m_filterEnabledClicked();
}

TEST_F(ToolbarPresenterTest, FilterEnableClickedInView_DisabledFilterInModelIfEnabled)
{
    ToolbarPresenter toolbarPresenter(m_mockWindowManager, m_mockToolbar, m_mockLogDataContext);

    ON_CALL(m_logMessageFilter, filterEnabled).WillByDefault(testing::Return(true));
    EXPECT_CALL(m_logMessageFilter, setFilterEnabled(false)).Times(1);

    m_filterEnabledClicked();
}

TEST_F(ToolbarPresenterTest, FilterEnableClickedInView_EnablesFilterInViewIfDisabled)
{
    ToolbarPresenter toolbarPresenter(m_mockWindowManager, m_mockToolbar, m_mockLogDataContext);

    ON_CALL(m_logMessageFilter, filterEnabled).WillByDefault(testing::Return(false));
    EXPECT_CALL(m_mockToolbar, setFilterEnabled(true)).Times(1);

    m_filterEnabledClicked();
}

TEST_F(ToolbarPresenterTest, FilterEnableClickedInView_DisabledFilterInViewIfEnabled)
{
    ToolbarPresenter toolbarPresenter(m_mockWindowManager, m_mockToolbar, m_mockLogDataContext);

    ON_CALL(m_logMessageFilter, filterEnabled).WillByDefault(testing::Return(true));
    EXPECT_CALL(m_mockToolbar, setFilterEnabled(false)).Times(1);

    m_filterEnabledClicked();
}

} // namespace Presenters::Tests