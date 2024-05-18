/*
 * Copyright (c) $originalComment.match("Copyright © (\d+)", 1, "-", "$today.year")$today.year. Tim Herreijgers
 * Licensed using the MIT license
 */
 
#pragma once

namespace Widgets
{
class MenuBar;
}
namespace Presenters
{

class MenuBarPresenter
{
public:
    explicit MenuBarPresenter(Widgets::MenuBar& view);

private:
    Widgets::MenuBar& m_view;
};

} // namespace Presenters