/*
 * Copyright (c) $originalComment.match("Copyright © (\d+)", 1, "-", "$today.year")$today.year. Tim Herreijgers
 * Licensed using the MIT license
 */

#include "model/settings_manager.h"
#include "model/log_level_color_settings.h"

#include <yaml-cpp/yaml.h>

#include <filesystem>
#include <iostream>
#include <fstream>

namespace Model
{

SettingsManager::SettingsManager()
{
    // if (!std::filesystem::exists("settings.yaml"))
    // {
    //     createYamlFile();
    // }

    // YAML::Node settings = YAML::LoadFile("settings.yaml");
}

void SettingsManager::createYamlFile()
{
    YAML::Node settings;

    YAML::Node textColours;
    textColours["TRACE"] = "FFFFFFFF";
    textColours["DEBUG"] = "FFFFFFFF";
    textColours["INFO"] = "FFFFFFFF";
    textColours["WARNING"] = "FFFFFFFF";
    textColours["ERROR"] = "FFFFFFFF";
    textColours["CRITICAL"] = "FFFFFFFF";

    YAML::Node backgroundColour;
    backgroundColour["TRACE"] = "000000FF";
    backgroundColour["DEBUG"] = "000000FF";
    backgroundColour["INFO"] = "000000FF";
    backgroundColour["WARNING"] = "000000FF";
    backgroundColour["ERROR"] = "000000FF";
    backgroundColour["CRITICAL"] = "000000FF";

    settings["TextColours"] = textColours;
    settings["BackgroundColours"] = backgroundColour;

    YAML::Emitter out;
    out << settings;

    std::ofstream filestream("settings.yaml");
    filestream << out.c_str();
}

auto SettingsManager::getLogLevelColorSettings() noexcept -> LogLevelColorSettings &
{
    return m_logLevelColorSettings;
}

} // namespace Model