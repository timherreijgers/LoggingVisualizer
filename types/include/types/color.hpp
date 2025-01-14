/*
 * Copyright © 2024-2025 Tim Herreijgers
 * Licensed using the MIT license
 */

#pragma once

#include <cinttypes>
#include <compare>

namespace Types
{

struct Color
{
    uint8_t red;
    uint8_t green;
    uint8_t blue;
    uint8_t alpha;

    [[nodiscard]] bool operator==(const Color&) const = default;
};

} // namespace Types