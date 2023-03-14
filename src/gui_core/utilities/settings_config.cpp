#include "settings_config.h"

#include "fstream"

nlohmann::json ReadConfigFile()
{
    std::fstream json_config_file;
    json_config_file.open("ConfigFile.json", std::ios::in);
    nlohmann::json json_data = nlohmann::json::parse(json_config_file);
    json_config_file.close();
    return json_data;
}

std::string GetConfigVariable(std::string config_variable)
{
    nlohmann::json json_data = ReadConfigFile();
    return json_data[config_variable].get<std::string>();
}

void ChangeConfigVariable(std::string config_variable, std::string new_config_value)
{
    nlohmann::json json_data = ReadConfigFile();
    json_data[config_variable] = new_config_value;

    std::fstream json_config_file;
    json_config_file.open("ConfigFile.json", std::ios::out);
    json_config_file << json_data;
    json_config_file.close();
}