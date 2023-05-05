#include <string>
#include <algorithm>

#include "imgui.h"

#include "application.h"
#include "settings_config.h"
#include "main_menu_bar.h"

MainMenuBar::MainMenuBar(Application* app) : m_app(app) {}

void MainMenuBar::OnAttach()
{
	std::string current_style = GetConfigVariable("GuiStyle");
	settings_variables.styles[current_style] = true;
}

void MainMenuBar::OnRender()
{
	if (ImGui::BeginMainMenuBar())
	{
		if (ImGui::BeginMenu("File"))
    	{
        	if (ImGui::MenuItem("Exit"))
				m_app->m_window->m_close_popup = true;

        	ImGui::EndMenu();
    	}

		if (ImGui::BeginMenu("Settings"))
    	{
			if (ImGui::BeginMenu("Color Theme"))
			{
				for (auto& color_style : settings_variables.styles)
				{
					if (ImGui::MenuItem(color_style.first.c_str(), "", color_style.second))
					{
						ChangeConfigVariable("GuiStyle", color_style.first);
						UpdateTheme();
						std::for_each(settings_variables.styles.begin(), settings_variables.styles.end(), 
							[&](auto& pair){ pair.second = false; });
						color_style.second = true;
					}
				}
				ImGui::EndMenu();
			}

        	ImGui::EndMenu();
    	}

		ImGui::EndMainMenuBar();
	}
}