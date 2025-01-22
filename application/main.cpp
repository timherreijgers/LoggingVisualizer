/*
 * Copyright © 2024-2025 Tim Herreijgers
 * Licensed using the MIT license
 */

#include "model/log_data_context_factory.hpp"
#include "model/settings_manager_factory.hpp"

#include "presenters/log_presenter.hpp"
#include "presenters/menu_bar_presenter.hpp"
#include "presenters/toolbar_presenter.hpp"

#include "windows/main_window.hpp"
#include "windows/window_manager.hpp"

#include <QApplication>

int main(int argc, char ** argv)
{
    QApplication application(argc, argv);

    Windows::WindowManager windowManager;

    auto& mainWindow = windowManager.getMainWindow();
    mainWindow.show();

    auto logDataContext = Model::LogDataContextFactory::createContext();

    Presenters::LogPresenter logPresenter(windowManager, mainWindow.getLogWidget(), *logDataContext, Model::SettingsManagerFactory::createSettingsManager());
    Presenters::MenuBarPresenter menuBarPresenter(windowManager, mainWindow.getMenuBar(), *logDataContext);
    Presenters::ToolbarPresenter toolbarPresenter(windowManager, mainWindow.getToolbar(), *logDataContext);

    return QApplication::exec();
}