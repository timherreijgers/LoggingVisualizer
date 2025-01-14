/*
 * Copyright © 2024 Tim Herreijgers
 * Licensed using the MIT license
 */

#pragma once

#include "types/color.hpp"

#include <QAbstractItemModel>

#include <functional>

namespace Widgets
{

enum class ColorType
{
    TEXT,
    BACKGROUND
};

class ILogLevelWidget
{
public:
    virtual ~ILogLevelWidget() = default;

    virtual void setModel(QAbstractItemModel * model) = 0;
    virtual void connectColorSelectionChanged(const std::function<void(int, ColorType, Types::Color)>& slot) = 0;
};

} // namespace Widgets