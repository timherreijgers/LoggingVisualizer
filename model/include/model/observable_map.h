/*
 * Copyright © 2024 Tim Herreijgers
 * Licensed using the MIT license
 */

#pragma once

#include <functional>
#include <map>

namespace Model
{

template <typename Key, typename Value>
class ObservableMap
{
public:
    using SubscriberFunction = std::function<void(std::map<Key, Value>&)>;

    class ObservableMapEntry
    {
    public:
        explicit ObservableMapEntry(Value& value, const std::function<void()>& entryChangedCallback) :
            m_value(value), m_entryChangedCallback(entryChangedCallback)
        {
        }

        void operator=(Value value)
        {
            m_value = value;
            m_entryChangedCallback();
        }

        explicit(false) operator const Value &() const
        {
            return m_value;
        }

        explicit(false) operator Value &()
        {
            return m_value;
        }

    private:
        Value& m_value;
        std::function<void()> m_entryChangedCallback;
    };

    [[nodiscard]] auto at(const Key& key) const -> const Value&
    {
        return m_map.at(key);
    }

    [[nodiscard]] auto containsKey(const Key& key) const -> bool
    {
        return m_map.contains(key);
    }

    [[nodiscard]] auto operator[](const Key& key) const -> const Value&
    {
        return m_map[key];
    }

    [[nodiscard]] auto operator[](const Key& key) -> ObservableMapEntry
    {
        return ObservableMapEntry(m_map[key], [this]() {
            if (m_subscriber)
            {
                m_subscriber(m_map);
            }
        });
    }

    void subscribe(SubscriberFunction subscriber) noexcept
    {
        m_subscriber = subscriber;
    }

    void setValue(std::map<Key, Value>&& value) noexcept
    {
        m_map = std::move(value);

        if (m_subscriber)
        {
            m_subscriber(m_map);
        }
    }

    [[nodiscard]] auto getValue() const -> const std::map<Key, Value>&
    {
        return m_map;
    }

private:
    std::map<Key, Value> m_map;
    SubscriberFunction m_subscriber;
};

} // namespace Model
