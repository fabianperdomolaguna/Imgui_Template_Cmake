#pragma once

#include <unordered_map>

#include "layer.h"
#include "application.h"

struct SettingsVariables
{
    std::unordered_map<std::string, bool> styles = { {"Dark", false}, {"Light", false} };
};

class MainMenuBar : public Layer
{
    Application* m_app;
    SettingsVariables settings_variables;

public:
    MainMenuBar(Application* app);
    void OnAttach() override;
    void OnRender() override;
};

void CloseAppPopup(bool& close_app, Application* app);