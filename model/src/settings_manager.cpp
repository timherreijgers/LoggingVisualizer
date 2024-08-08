/*
 * Copyright (c) $originalComment.match("Copyright © (\d+)", 1, "-", "$today.year")$today.year. Tim Herreijgers
 * Licensed using the MIT license
 */

#include "model/settings_manager.h"

#include "model/log_level_color_settings_entry.h"

#include "yaml-cpp/yaml.h"

#include <filesystem>
#include <iostream>
#include <fstream>
#include <string>
#include <string_view>

namespace Model
{

static constexpr auto SETTINGS_FILE_NAME = "settings.yaml";

static Types::Color convertStringFromHtmlColor(std::string_view htmlcolor)
{
    const auto colorAsInt = std::stoul(htmlcolor.substr(1).data(), nullptr, 16);
    return Types::Color
    {
        static_cast<uint8_t>(colorAsInt >> 24 & 0xFF),
        static_cast<uint8_t>(colorAsInt >> 16 & 0xFF),
        static_cast<uint8_t>(colorAsInt >> 8 & 0xFF),
        static_cast<uint8_t>(colorAsInt >> 0 & 0xFF),
    };
}

SettingsManager::SettingsManager()
{
    if (!std::filesystem::exists(SETTINGS_FILE_NAME))
    {
        createYamlFile();
    }

    loadSettingsFromYamlFile();
}

void SettingsManager::createYamlFile()
{
    static constexpr std::array DEFAULT_LOG_LEVELS = {"TRACE", "DEBUG", "INFO", "WARNING", "ERROR", "CRITICAL"};

    YAML::Node settings;
    settings["highlightColors"] = YAML::Node{};

    size_t index = 0;
    for (const auto& level : DEFAULT_LOG_LEVELS)
    {
        settings["highlightColors"][index] = YAML::Node{};
        settings["highlightColors"][index]["level"] = level;
        settings["highlightColors"][index]["text"] = "#000000FF";
        settings["highlightColors"][index]["background"] = "#FFFFFFFF";

        index++;
    }

    YAML::Emitter out;
    out << settings;

    std::ofstream filestream(SETTINGS_FILE_NAME);
    filestream << out.c_str();
}

void SettingsManager::loadSettingsFromYamlFile()
{
    YAML::Node settings = YAML::LoadFile(SETTINGS_FILE_NAME);

    const auto levels = settings["highlightColors"];

    for (const auto levelData : levels)
    {
        const auto level = levelData["level"].as<std::string>();
        const auto textColor = convertStringFromHtmlColor(levelData["text"].as<std::string>());
        const auto backgroundColor = convertStringFromHtmlColor(levelData["background"].as<std::string>());

        m_logLevelColorSettings.emplace_back(level, textColor, backgroundColor);
    }
}

auto SettingsManager::getLogLevelColorSettings() noexcept -> ObservableVector<LogLevelColorSettingsEntry>&
{
    return m_logLevelColorSettings;
}

} // namespace Model