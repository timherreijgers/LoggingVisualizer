/*
 * Copyright © 2025 Tim Herreijgers
 * Licensed using the MIT license
 */

#include "settings_manager.hpp"

#include "types/color.hpp"

#include <yaml-cpp/yaml.h>

#include <algorithm>
#include <filesystem>
#include <format>
#include <fstream>

namespace Model::NewSettings
{

static Types::Color convertStringFromHtmlColor(std::string_view htmlcolor)
{
    const auto colorAsInt = std::stoul(htmlcolor.substr(1).data(), nullptr, 16);
    return Types::Color{
        static_cast<uint8_t>(colorAsInt >> 24 & 0xFF),
        static_cast<uint8_t>(colorAsInt >> 16 & 0xFF),
        static_cast<uint8_t>(colorAsInt >> 8 & 0xFF),
        static_cast<uint8_t>(colorAsInt >> 0 & 0xFF),
    };
}

static std::string convertColorToString(const Types::Color& color)
{
    return std::format("#{:02X}{:02X}{:02X}{:02X}", color.red, color.green, color.blue, color.alpha);
}

SettingsManager::SettingsManager() :
    m_yamlLoadingGroupFunctions(createYamlLoadingGroupFunctions())

{
    m_groups.emplace_back("Log Levels");

    if (std::filesystem::exists("settings2.yaml"))
    {
        loadSettingsFromYamlFile();
    }
    else
    {
        auto& logLevelsGroup = *std::ranges::find_if(m_groups, [](const auto& group) { return group.getName() == "Log Levels"; });

        std::unique_ptr<SettingsNode> logColorSettingNode = std::make_unique<SettingsNode>(&m_settingsTree);
        LogColorSetting logColorSetting{*logColorSettingNode};
        m_settingsTree.addChild(std::move(logColorSettingNode));
        logColorSetting.addLogColorSettings("TRACE", Types::Color{0x00, 0x00, 0x00, 0xFF},
                                            Types::Color{0xFF, 0xFF, 0xFF, 0xFF});
        logColorSetting.addLogColorSettings("DEBUG", Types::Color{0x00, 0x00, 0x00, 0xFF},
                                            Types::Color{0xFF, 0xFF, 0xFF, 0xFF});
        logColorSetting.addLogColorSettings("INFO", Types::Color{0x00, 0x00, 0x00, 0xFF},
                                            Types::Color{0xFF, 0xFF, 0xFF, 0xFF});
        logColorSetting.addLogColorSettings("WARNING", Types::Color{0x00, 0x00, 0x00, 0xFF},
                                            Types::Color{0xFF, 0xFF, 0xFF, 0xFF});
        logColorSetting.addLogColorSettings("ERROR", Types::Color{0x00, 0x00, 0x00, 0xFF},
                                            Types::Color{0xFF, 0xFF, 0xFF, 0xFF});
        logColorSetting.addLogColorSettings("CRITICAL", Types::Color{0x00, 0x00, 0x00, 0xFF},
                                            Types::Color{0xFF, 0xFF, 0xFF, 0xFF});
        logLevelsGroup.addSetting(std::move(logColorSetting));
    }
}


auto SettingsManager::getSettingGroups() const noexcept -> const std::vector<SettingsGroup>&
{
    return m_groups;
}

auto SettingsManager::getSettingGroup(SettingsGroupId id) const noexcept -> const SettingsGroup&
{
    return m_groups[std::to_underlying(id)];
}

auto SettingsManager::getSettingGroup(SettingsGroupId id) noexcept -> SettingsGroup&
{
    return m_groups[std::to_underlying(id)];
}

void SettingsManager::saveSettings() noexcept
{
    YAML::Node settings;
    settings["Log Levels"] = YAML::Node{};

    const auto& logLevelGroup = getSettingGroup(SettingsGroupId::LOG_LEVELS).getSettings();
    const auto& logColorSettingEntries = std::get<LogColorSetting>(logLevelGroup[0]);

    size_t index = 0;
    for (const auto& setting : logColorSettingEntries.getLogColorSettingsEntries())
    {
        settings["Log Levels"][index] = YAML::Node{};
        settings["Log Levels"][index]["level"] = setting.getLogLevel();
        settings["Log Levels"][index]["foregroundColor"] = convertColorToString(setting.getForegroundColor());
        settings["Log Levels"][index]["backgroundColor"] = convertColorToString(setting.getBackgroundColor());

        index++;
    }

    YAML::Emitter out;
    out << settings;

    std::ofstream filestream("settings2.yaml");
    filestream << out.c_str();

    resetModified();
}

auto SettingsManager::connectSettingsModified(SettingsModifiedSignal::slot_type slot) -> Signals::scoped_connection
{
    return m_settingsTree.connectSettingsModified(std::move(slot));
}

auto SettingsManager::isModified() const noexcept -> bool
{
    return m_settingsTree.isModified();
}

void SettingsManager::resetModified() noexcept
{
    m_settingsTree.setModified(false);
}

auto SettingsManager::createYamlLoadingGroupFunctions() -> std::map<std::string_view, std::function<void(const YAML::Node&)>>
{
    std::map<std::string_view, std::function<void(const YAML::Node&)>> result;

    result["Log Levels"] = [this](const auto& node) {
        loadLogLevelSettingsFromYamlFile(node);
    };

    return result;
}

void SettingsManager::loadSettingsFromYamlFile()
{
    YAML::Node root = YAML::LoadFile("settings2.yaml");

    for (const auto& group : m_groups)
    {
        if (!root[group.getName()])
            continue;

        const auto node = root[group.getName()];
        m_yamlLoadingGroupFunctions.at(group.getName())(node);
    }

    resetModified();
}

void SettingsManager::loadLogLevelSettingsFromYamlFile(const YAML::Node& node)
{
    const auto found = std::ranges::find_if(m_groups,
                                            [](const auto& group) { return group.getName() == "Log Levels"; });

    if (found == m_groups.end())
        return;

    auto& logLevelsGroup = *std::ranges::find_if(m_groups, [](const auto& group) { return group.getName() == "Log Levels"; });

    std::unique_ptr<SettingsNode> logColorSettingNode = std::make_unique<SettingsNode>(&m_settingsTree);
    LogColorSetting logColorSetting{*logColorSettingNode};
    m_settingsTree.addChild(std::move(logColorSettingNode));

    for (const auto& entry : node)
    {
        logColorSetting.addLogColorSettings(
            entry["level"].as<std::string>(),
            convertStringFromHtmlColor(entry["foregroundColor"].as<std::string>()),
            convertStringFromHtmlColor(entry["backgroundColor"].as<std::string>()));
    }

    logLevelsGroup.addSetting(std::move(logColorSetting));
}

} // namespace Model::NewSettings