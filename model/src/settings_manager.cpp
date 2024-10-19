/*
 * Copyright © 2024 Tim Herreijgers
 * Licensed using the MIT license
 */

#include "model/settings_manager.hpp"

#include "model/log_level_color_settings_entry.hpp"

#include <fmt/format.h>
#include <yaml-cpp/yaml.h>

#include <filesystem>
#include <fstream>
#include <string>
#include <string_view>

namespace Model
{

static constexpr auto SETTINGS_FILE_NAME = "settings.yaml";

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
    return fmt::format("#{:02x}{:02x}{:02x}{:02x}", color.red, color.green, color.blue, color.alpha);
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

void SettingsManager::setLogLevelColorSettings(std::string level, Types::Color textColor, Types::Color backgroundColor)
{
    auto result = std::ranges::find_if(m_logLevelColorSettings, [&level](const auto& entry) { return entry.level == level; });
    if (result != m_logLevelColorSettings.end())
    {
        result->textColor = textColor;
        result->backgroundColor = backgroundColor;
        m_settingsChangedSignal();
    }
}

auto SettingsManager::getLogLevelColorSettings() noexcept -> const std::vector<LogLevelColorSettingsEntry>&
{
    return m_logLevelColorSettings;
}

void SettingsManager::saveSettings()
{
    YAML::Node settings;
    settings["highlightColors"] = YAML::Node{};

    size_t index = 0;
    for (const auto& setting : getLogLevelColorSettings())
    {
        settings["highlightColors"][index] = YAML::Node{};
        settings["highlightColors"][index]["level"] = setting.level;
        settings["highlightColors"][index]["text"] = convertColorToString(setting.textColor);
        settings["highlightColors"][index]["background"] = convertColorToString(setting.backgroundColor);

        index++;
    }

    YAML::Emitter out;
    out << settings;

    std::ofstream filestream(SETTINGS_FILE_NAME);
    filestream << out.c_str();
}

void SettingsManager::connectSettingsChangedSignal(SettingsChangedSignal::slot_type slot)
{
    m_settingsChangedSignal.connect(std::move(slot));
}

} // namespace Model