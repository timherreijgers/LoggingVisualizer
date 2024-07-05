/*
 * Copyright © 2024 Tim Herreijgers
 * Licensed using the MIT license
 */

#pragma once

#include <map>
#include <functional>

namespace Model
{

template<typename Key, typename Value>
class ObservableMap
{
public:
    [[nodiscard]] auto at(const Key & key) const -> const Value &
    {
        return m_map.at(key);
    }

    [[nodiscard]] auto containsKey(const Key & key) const -> bool
    {
        return m_map.contains(key);
    }

    [[nodiscard]] auto operator[](const Key & key) const -> const Value&
    {
        return m_map[key];
    }

    void setValue(const Key & key, Value value)
    {
        m_map[key] = value;

        if (m_subscriber)
        {
            m_subscriber(m_map);
        }
    }

    void subscribe(std::function<void(std::map<Key, Value> &)> subscriber) noexcept
    {
        m_subscriber = subscriber;
    }

    void setValue(std::map<Key, Value>&& value) noexcept
    {
        m_map = std::move(value);

        if(m_subscriber)
        {
            m_subscriber(m_map);
        }
    }

private:
    std::map<Key, Value> m_map;
    std::function<void(std::map<Key, Value>&)> m_subscriber;
};

} // namespace Model
