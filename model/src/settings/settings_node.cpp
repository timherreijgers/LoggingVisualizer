/*
 * Copyright © 2025 Tim Herreijgers
 * Licensed using the MIT license
 */

#include "settings_node.hpp"

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

} // namespace Model