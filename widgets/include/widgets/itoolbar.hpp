/*
 * Copyright © 2024 Tim Herreijgers
 * Licensed using the MIT license
 */

#pragma once

#include <QString>

#include <functional>

namespace Widgets
{

class IToolbar
{
public:
    virtual ~IToolbar() = default;;

    virtual void setFilterEnabled(bool enabled) = 0;
    virtual void connectFilterChanged(std::function<void(const QString&)> slot) = 0;
    virtual void connectFilterEnabledClicked(std::function<void()> slot) = 0;
};

} // namespace Widgets