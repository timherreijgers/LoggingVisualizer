/*
 * Copyright © 2025 Tim Herreijgers
 * Licensed using the MIT license
 */

#include "model/settings/settings_node.hpp"

#include <algorithm>
#include <cassert>

namespace Model
{

SettingsNode::SettingsNode(SettingsNode * parent) :
    m_parent(parent)
{
}

void SettingsNode::addChild(std::unique_ptr<SettingsNode> child)
{
    child->setParent(this);
    m_children.emplace_back(std::move(child));
}

void SettingsNode::setParent(SettingsNode * parent)
{
    m_parent = parent;
}

void SettingsNode::setModified(bool modified) noexcept
{
    modified =  modified || std::ranges::any_of(m_children, [](const auto& child){return child->isModified();});
    m_modified = modified;

    if (m_parent != nullptr)
    {
        m_parent->setModified(modified);
    }
}

auto SettingsNode::isModified() const noexcept -> bool
{
    return m_modified;
}

void SettingsNode::resetModified() noexcept
{
    m_modified = false;

    for (auto& child : m_children)
        child->resetModified();
}

} // namespace Model