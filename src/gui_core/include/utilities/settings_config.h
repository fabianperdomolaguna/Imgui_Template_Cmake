#pragma once

#include "nlohmann/json.hpp"

nlohmann::json ReadConfigFile();
std::string GetConfigVariable(std::string config_variable);
void ChangeConfigVariable(std::string config_variable, std::string new_config_value);