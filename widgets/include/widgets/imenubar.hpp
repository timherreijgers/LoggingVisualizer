/*
 * Copyright © 2024-2025 Tim Herreijgers
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

    virtual void connectOpenFileClicked(const std::function<void()>& slot) = 0;
    virtual void connectCloseFileClicked(const std::function<void()>& slot) = 0;
    virtual void connectPreferencesClicked(const std::function<void()>& slot) = 0;
    virtual void connectExitClicked(const std::function<void()>& slot) = 0;
};

} // namespace Widgets
