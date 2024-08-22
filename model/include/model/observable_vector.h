/*
 * Copyright © 2024 Tim Herreijgers
 * Licensed using the MIT license
 */

#pragma once

#include <functional>
#include <vector>
#include <utility>

namespace Model
{

template <typename T>
class ObservableVector
{
public:
    using SubscriberFunction = std::function<void(std::vector<T> &)>;

    class ObservableVectorEntry
    {
    public:
        explicit ObservableVectorEntry(T & value, const std::function<void()> & entryChangedCallback) :
            m_value(value), m_entryChangedCallback(entryChangedCallback)
        {
        }

        void operator=(T value)
        {
            m_value = value;
            m_entryChangedCallback();
        }

        explicit(false) operator const T &() const
        {
            return m_value;
        }

        explicit(false) operator T &()
        {
            return m_value;
        }

    private:
        T & m_value;
        std::function<void()> m_entryChangedCallback;
    };

    [[nodiscard]] auto at(size_t index) const -> const T &
    {
        return m_vector.at(index);
    }

    [[nodiscard]] auto operator[](size_t index) const -> const T &
    {
        return m_vector[index];
    }

    [[nodiscard]] auto operator[](size_t index) -> ObservableVectorEntry
    {
        return ObservableVectorEntry(m_vector[index], [this]() {
            if (m_subscriber)
            {
                m_subscriber(m_vector);
            }
        });
    }

    void subscribe(SubscriberFunction subscriber) noexcept
    {
        m_subscriber = subscriber;
    }

    void setValue(std::vector<T> value) noexcept
    {
        m_vector = std::move(value);

        if (m_subscriber)
        {
            m_subscriber(m_vector);
        }
    }

    template <class... Args>
    void emplace_back(Args &&... args)
    {
        m_vector.emplace_back(std::forward<Args>(args)...);

        if (m_subscriber)
        {
            m_subscriber(m_vector);
        }
    }

    constexpr void push_back(const T& value)
    {
        m_vector.push_back(value);

        if (m_subscriber)
        {
            m_subscriber(m_vector);
        }
    }

    constexpr void push_back(T value)
    {
        m_vector.push_back(std::move(value));

        if (m_subscriber)
        {
            m_subscriber(m_vector);
        }
    }

    [[nodiscard]] auto getValue() const -> const std::vector<T> &
    {
        return m_vector;
    }

private:
    std::vector<T> m_vector;
    SubscriberFunction m_subscriber;
};

} // namespace Model
