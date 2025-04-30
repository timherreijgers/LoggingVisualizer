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

    virtual void setModified(bool modified) noexcept;
    [[nodiscard]] virtual auto isModified() const noexcept -> bool;

protected:
    virtual void resetModified() noexcept;

private:
    SettingsNode * m_parent;
    std::vector<std::unique_ptr<SettingsNode>> m_children;
    bool m_modified = false;
};

} // namespace Model