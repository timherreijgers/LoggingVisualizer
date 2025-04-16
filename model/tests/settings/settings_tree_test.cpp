/*
 * Copyright © 2025 Tim Herreijgers
 * Licensed using the MIT license
 */

#include "model/settings/settings_object.hpp"
#include "model/settings/settings_tree.hpp"


#include <gtest/gtest.h>

namespace Model::Tests
{

class SettingsTreeTest : public ::testing::Test
{
protected:
    template <typename T>
    [[nodiscard]] auto addChildToTree(SettingsTree& tree, T value) -> SettingsObject<T>&
    {
        auto child = std::make_unique<SettingsObject<int>>(&tree, value);
        auto pChild = child.get();
        tree.addChild(std::move(child));
        return *pChild;
    }
};

TEST_F(SettingsTreeTest, NodeIsModified_SetsIsModifiedOnTreeRoot)
{
    SettingsTree tree{};
    auto& child = addChildToTree<int>(tree, 10);

    child.setNewValue(20);

    ASSERT_TRUE(tree.isModified());
}

TEST_F(SettingsTreeTest, NodeIsModifiedAndSetBackToPreviousValue_DoesntSetIsModifiedOnTreeRoot)
{
    SettingsTree tree{};
    auto& child = addChildToTree<int>(tree, 10);

    child.setNewValue(20);
    child.setNewValue(10);

    ASSERT_FALSE(tree.isModified());
}

} // namespace Model::Tests