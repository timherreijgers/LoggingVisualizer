/*
 * Copyright © 2025 Tim Herreijgers
 * Licensed using the MIT license
 */

#pragma once

#include "settings_node.hpp"

#include <concepts>

namespace Model
{

template <std::equality_comparable T>
class SettingsObject : public SettingsNode
{
public:
    explicit SettingsObject(SettingsNode * parent, const T& t) :
        SettingsNode(parent), m_originalValue(t)
    {
    }

    void setValue(const T& t)
    {
        m_newValue = t;

        if (m_originalValue != m_newValue)
        {
            m_parent->setModified(true);
        }
        else
        {
            m_parent->setModified(false);
        }
    }

private:
    T m_originalValue;
    T m_newValue;
};

} // namespace Model