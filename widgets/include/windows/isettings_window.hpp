/*
 * Copyright © 2025 Tim Herreijgers
 * Licensed using the MIT license
 */

#pragma once

#include "widgets/ilog_level_widget.hpp"

namespace Windows
{
class ISettingsWindow
{
public:
    ISettingsWindow() = default;
    virtual ~ISettingsWindow() = default;
    ISettingsWindow(const ISettingsWindow&) = delete;
    ISettingsWindow(ISettingsWindow&&) = delete;
    ISettingsWindow& operator=(const ISettingsWindow&) = delete;
    ISettingsWindow& operator=(const ISettingsWindow&&) = delete;

    [[nodiscard]] virtual Widgets::ILogLevelWidget& getLogLevelWidget() const noexcept = 0;
    virtual void showWindow() = 0;
};

} // namespace Windows
