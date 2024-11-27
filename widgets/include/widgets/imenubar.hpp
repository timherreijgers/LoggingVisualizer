/*
 * Copyright © 2024 Tim Herreijgers
 * Licensed using the MIT license
 */

#pragma once

#include <functional>

namespace Widgets
{

class IMenuBar
{
public:
    virtual ~IMenuBar() = default;

    virtual void connectOpenFileClicked(std::function<void()> slot) = 0;
    virtual void connectCloseFileClicked(std::function<void()> slot) = 0;
    virtual void connectPreferencesClicked(std::function<void()> slot) = 0;
    virtual void connectExitClicked(std::function<void()> slot) = 0;
};

} // namespace Widgets
