/*
 * Copyright (c) $originalComment.match("Copyright © (\d+)", 1, "-", "$today.year")$today.year. Tim Herreijgers
 * Licensed using the MIT license
 */

#include "presenters/menu_bar_presenter.h"

#include "widgets/menubar.h"

namespace Presenters
{

MenuBarPresenter::MenuBarPresenter(Widgets::MenuBar & view)
    : m_view(view)
{
    m_view.disableCloseFileOption();
}

} // namespace Presenters