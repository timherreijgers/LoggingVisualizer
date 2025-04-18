/*
 * Copyright © 2025 Tim Herreijgers
 * Licensed using the MIT license
 */

#include <utility>

#include "model/settings/settings_tree.hpp"

namespace Model
{

SettingsTree::SettingsTree() :
    SettingsNode(nullptr)
{
}

auto SettingsTree::connectSettingsModified(SettingsModifiedSignal::slot_type slot) -> Signals::scoped_connection
{
    return m_settingsModified.connect(std::move(slot));
}

void SettingsTree::setModified(bool modified) noexcept
{
    SettingsNode::setModified(modified);
    m_settingsModified(modified);
}

} // namespace Model