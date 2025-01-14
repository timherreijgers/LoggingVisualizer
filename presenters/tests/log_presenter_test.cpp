/*
 * Copyright © 2024-2025 Tim Herreijgers
 * Licensed using the MIT license
 */

#include "mocks/model/mock_filtered_log_message_view.hpp"
#include "mocks/model/mock_log_data_context.hpp"
#include "mocks/widgets/mock_log_widget.hpp"
#include "mocks/windows/mock_window_manager.hpp"
#include "presenters/log_presenter.hpp"

#include "gtest/gtest.h"

namespace Presenters::Tests
{

class LogPresenterTests : public ::testing::Test
{
public:
    Widgets::Mocks::MockLogWidget m_mockLogWidget;
    Model::Mocks::MockLogDataContext m_mockLogDataContext;
    Model::Mocks::MockFilteredLogMessageView m_mockFilteredLogMessageView;
    Windows::Mocks::MockWindowManager m_windowManager;
};

TEST_F(LogPresenterTests, FileDroppedInView_CallsOpenFileInModel)
{
    std::function<void(std::string_view)> callback;
    ON_CALL(m_mockLogWidget, connectOnFileDropped).WillByDefault([&callback](auto c) { callback = c; });
    EXPECT_CALL(m_mockLogDataContext, openFile(::testing::_)).Times(1);

    LogPresenter presenter(m_windowManager, m_mockLogWidget, m_mockLogDataContext);

    callback("");
}

TEST_F(LogPresenterTests, FileDroppedInView_CallsOpenFileInModel_WithCorrectPath)
{
    std::function<void(std::string_view)> callback;
    ON_CALL(m_mockLogWidget, connectOnFileDropped).WillByDefault([&callback](auto c) { callback = c; });
    EXPECT_CALL(m_mockLogDataContext, openFile(std::filesystem::path("/test/path/to/file.txt"))).Times(1);

    LogPresenter presenter(m_windowManager, m_mockLogWidget, m_mockLogDataContext);

    callback("/test/path/to/file.txt");
}

TEST_F(LogPresenterTests, LogMessagesChanged_WithoutMessages_CallsClearLogMessagesOnView)
{
    Model::logMessageChangedSignal callback;
    ON_CALL(m_mockLogDataContext, connectLogMessagesChanged).WillByDefault([&callback](auto c) { return callback.connect(c); });
    ON_CALL(m_mockLogDataContext, getLogMessages).WillByDefault(testing::ReturnRef(m_mockFilteredLogMessageView));
    ON_CALL(m_mockFilteredLogMessageView, empty()).WillByDefault(testing::Return(true));
    EXPECT_CALL(m_mockLogWidget, clearLogMessages()).Times(1);

    LogPresenter presenter(m_windowManager, m_mockLogWidget, m_mockLogDataContext);

    callback();
}

TEST_F(LogPresenterTests, LogMessagesChanged_WithMessages_CallsSetLogMessages)
{
    Model::logMessageChangedSignal callback;
    ON_CALL(m_mockLogDataContext, connectLogMessagesChanged).WillByDefault([&callback](auto c) { return callback.connect(c); });
    ON_CALL(m_mockLogDataContext, getLogMessages).WillByDefault(testing::ReturnRef(m_mockFilteredLogMessageView));
    ON_CALL(m_mockFilteredLogMessageView, empty()).WillByDefault(testing::Return(false));
    EXPECT_CALL(m_mockLogWidget, setLogMessages(testing::_)).Times(1);

    LogPresenter presenter(m_windowManager, m_mockLogWidget, m_mockLogDataContext);

    callback();
}

TEST_F(LogPresenterTests, LogMessagesChanged_WithMessages_CallsSetLogMessagesWithCorrectMessages)
{
    Model::logMessageChangedSignal callback;
    const Widgets::ItemModels::AbstractItemModel<Types::LogEntry> * itemModel;

    ON_CALL(m_mockLogDataContext, connectLogMessagesChanged).WillByDefault([&callback](auto c) { return callback.connect(c); });
    ON_CALL(m_mockLogDataContext, getLogMessages).WillByDefault(testing::ReturnRef(m_mockFilteredLogMessageView));
    ON_CALL(m_mockFilteredLogMessageView, empty()).WillByDefault(testing::Return(false));
    ON_CALL(m_mockFilteredLogMessageView, size()).WillByDefault(testing::Return(5));

    ON_CALL(m_mockLogWidget, setLogMessages).WillByDefault([&itemModel](const Widgets::ItemModels::AbstractItemModel<Types::LogEntry>& model) { itemModel = &model; });
    EXPECT_CALL(m_mockLogWidget, setLogMessages(testing::_)).Times(1);

    LogPresenter presenter(m_windowManager, m_mockLogWidget, m_mockLogDataContext);

    callback();
    ASSERT_EQ(itemModel->columnCount(), 1);
    ASSERT_EQ(itemModel->rowCount(), 5);
}

} // namespace Presenters::Tests