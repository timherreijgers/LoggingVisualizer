/*
 * Copyright © 2024 Tim Herreijgers
 * Licensed using the MIT license
 */

#pragma once

#include <optional>
#include <functional>

namespace Model
{

template<typename T>
class Observable
{
public:
    explicit Observable() = default;

    void subscribe(std::function<void(const T &)> subscriber) noexcept
    {
        m_subscriber = subscriber;
    }

    void setValue(T&& value) noexcept
    {
        m_data = std::move(value);

        if(m_subscriber)
        {
            m_subscriber(m_data.value());
        }
    }

    [[nodiscard]] auto hasData() const noexcept -> bool
    {
        return m_data.has_value();
    }

    [[nodiscard]] auto getData() const -> const T&
    {
        return m_data.value();
    }

private:
    std::optional<T> m_data;
    std::function<void(const T &)> m_subscriber;
};

} // namespace Model