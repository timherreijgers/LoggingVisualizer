/*
 * Copyright © 2025 Tim Herreijgers
 * Licensed using the MIT license
 */

#pragma once

#include "settings_node.hpp"
#include "model/signal.hpp"

namespace Model
{

class SettingsTree : public SettingsNode
{
public:
    using SettingsModifiedSignal = Signals::signal<void(bool)>;

    explicit SettingsTree();
    [[nodiscard]] auto connectSettingsModified(SettingsModifiedSignal::slot_type slot) -> Signals::scoped_connection;
    void setModified(bool modified) noexcept override;

private:
    SettingsModifiedSignal m_settingsModified;
};

} // namespace Model