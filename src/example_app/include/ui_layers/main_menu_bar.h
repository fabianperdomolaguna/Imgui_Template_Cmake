#pragma once

#include <unordered_map>

#include "application.h"
#include "layer.h"

struct MenuVariables
{
	bool close_app = false;
    std::unordered_map<std::string, bool> styles = { {"Dark", false}, {"Light", false} };
};

class MainMenuBar : public Layer
{
    Application* m_app;
    MenuVariables menu_variables;

public:
    MainMenuBar(Application* app);
    void OnAttach() override;
    void OnRender() override;
};

void CloseAppPopup(bool& close_app, Application* app);