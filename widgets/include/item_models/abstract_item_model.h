/*
 * Copyright © 2024 Tim Herreijgers
 * Licensed using the MIT license
 */

#pragma once

#include <cstddef>

namespace Widgets::ItemModels
{

template<typename T>
class AbstractItemModel
{
public:
    explicit AbstractItemModel() = default;
    virtual ~AbstractItemModel() = default;
    AbstractItemModel(const AbstractItemModel&) = delete;
    AbstractItemModel& operator=(const AbstractItemModel&) = delete;
    AbstractItemModel(AbstractItemModel&&) = default;
    AbstractItemModel& operator=(AbstractItemModel&&) = default;

    [[nodiscard]] virtual auto rowCount() const noexcept -> int = 0;
    [[nodiscard]] virtual auto columnCount() const noexcept -> int = 0;
    [[nodiscard]] virtual auto data(size_t row, size_t column) const -> T = 0;
};

} // namespace Widgets::ItemModels