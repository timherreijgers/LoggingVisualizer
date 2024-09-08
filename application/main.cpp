/*
 * Copyright © 2024 Tim Herreijgers
 * Licensed using the MIT license
 */

#include <QApplication>

#pragma push_macro("signals")
#pragma push_macro("slots")
#undef signals
#undef slots
#include "model/log_data_context_factory.h"
#pragma pop_macro("signals")
#pragma pop_macro("slots")

#include "presenters/log_presenter.h"
#include "presenters/menu_bar_presenter.h"
#include "presenters/toolbar_presenter.h"

#include "windows/main_window.h"
#include "windows/window_manager.h"

int main(int argc, char **argv)
{
    QApplication application(argc, argv);

    auto &mainWindow = Windows::WindowManager::createMainWindow();
    mainWindow.show();

    auto logDataContext = Model::LogDataContextFactory::createContext();

    Presenters::LogPresenter logPresenter(mainWindow.getLogWidget(), *logDataContext);
    Presenters::MenuBarPresenter menuBarPresenter(mainWindow.getMenuBar(), *logDataContext);
    Presenters::ToolbarPresenter toolbarPresenter(mainWindow.getToolbar(), *logDataContext);

    return QApplication::exec();
}