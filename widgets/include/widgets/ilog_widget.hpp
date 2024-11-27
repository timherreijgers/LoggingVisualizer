/*
 * Copyright © 2024 Tim Herreijgers
 * Licensed using the MIT license
 */

#pragma once

#include "item_models/abstract_item_model.hpp"
#include "types/highlight_color_pair.hpp"
#include "types/log_entry.hpp"

#include <functional>
#include <map>
#include <string_view>

namespace Widgets
{
class ILogWidget
{
public:
    virtual ~ILogWidget() = default;

    virtual void setLogMessages(const Widgets::ItemModels::AbstractItemModel<Types::LogEntry>& messages) noexcept = 0;
    virtual void clearLogMessages() noexcept = 0;

    virtual void setHighlightColors(std::map<std::string, Types::HighlightColorPair> colorMap) noexcept = 0;

    virtual void connectOnFileDropped(std::function<void(std::string_view)> slot) = 0;
};

} // namespace Widgets