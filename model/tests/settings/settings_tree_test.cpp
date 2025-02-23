/*
 * Copyright © 2025 Tim Herreijgers
 * Licensed using the MIT license
 */

#include "settings/settings_object.hpp"
#include "settings/settings_tree.hpp"


#include <gtest/gtest.h>

namespace Model::Tests
{

class SettingsTreeTest : public ::testing::Test
{
};

TEST_F(SettingsTreeTest, NodeIsModified_SetsIsModifiedOnTreeRoot)
{
    SettingsTree tree{};

    auto child = std::make_unique<SettingsObject<int>>(&tree, 10);
    auto pChild = child.get();
    tree.addChild(std::move(child));

    pChild->setValue(20);

    ASSERT_TRUE(tree.isModified());
}

TEST_F(SettingsTreeTest, NodeIsModifiedAndSetBackToPreviousValue_DoesntSetIsModifiedOnTreeRoot)
{
    SettingsTree tree{};

    auto child = std::make_unique<SettingsObject<int>>(&tree, 10);
    auto pChild = child.get();
    tree.addChild(std::move(child));

    pChild->setValue(20);
    pChild->setValue(10);

    ASSERT_FALSE(tree.isModified());
}

} // namespace Model::Tests