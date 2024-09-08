/*
 * Copyright © 2024 Tim Herreijgers
 * Licensed using the MIT license
 */

#pragma once

#include <functional>

namespace Model
{

class ILogMessageFilter
{
public:
    ILogMessageFilter() = default;
    virtual ~ILogMessageFilter() = default;
    ILogMessageFilter(const ILogMessageFilter&) = delete;
    ILogMessageFilter& operator=(const ILogMessageFilter&) = delete;
    ILogMessageFilter(ILogMessageFilter&&) = delete;
    ILogMessageFilter& operator=(ILogMessageFilter&&) = delete;

    virtual void setFilter(const std::string& filter) noexcept = 0;
    virtual void setFilterEnabled(bool enabled) noexcept = 0;
    [[nodiscard]] virtual auto filterEnabled() const noexcept -> bool = 0;
};

}