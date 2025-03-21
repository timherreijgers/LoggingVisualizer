/*
 * Copyright © 2025 Tim Herreijgers
 * Licensed using the MIT license
 */

#pragma once

#include <memory>
#include <vector>

namespace Model
{

class SettingsNode
{
public:
    explicit SettingsNode(SettingsNode * parent);
    virtual ~SettingsNode() = default;

    void addChild(std::unique_ptr<SettingsNode> child);
    void setParent(SettingsNode * parent);

    void setModified(bool modified) noexcept;
    [[nodiscard]] virtual auto isModified() const noexcept -> bool;

protected:
    SettingsNode * m_parent;

private:
    std::vector<std::unique_ptr<SettingsNode>> m_children;
    bool m_modified = false;
};

} // namespace Model