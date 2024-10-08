/*
 * Copyright © 2024 Tim Herreijgers
 * Licensed using the MIT license
 */

#include "model/log_data_context_factory.h"

#include "presenters/log_presenter.h"
#include "presenters/menu_bar_presenter.h"
#include "presenters/toolbar_presenter.h"

#include "windows/main_window.h"
#include "windows/window_manager.h"

#include <QApplication>

int main(int argc, char ** argv)
{
    QApplication application(argc, argv);

    Windows::WindowManager windowManager;

    auto& mainWindow = windowManager.getMainWindow();
    mainWindow.show();

    auto logDataContext = Model::LogDataContextFactory::createContext();

    Presenters::LogPresenter logPresenter(windowManager, mainWindow.getLogWidget(), *logDataContext);
    Presenters::MenuBarPresenter menuBarPresenter(windowManager, mainWindow.getMenuBar(), *logDataContext);
    Presenters::ToolbarPresenter toolbarPresenter(windowManager, mainWindow.getToolbar(), *logDataContext);

    return QApplication::exec();
}