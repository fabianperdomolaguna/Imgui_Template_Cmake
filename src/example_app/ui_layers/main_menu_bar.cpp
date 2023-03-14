#include <string>
#include <algorithm>

#include "application.h"
#include "imgui_context.h"
#include "settings_config.h"
#include "main_menu_bar.h"

#include "imgui.h"

MainMenuBar::MainMenuBar(Application* app) : m_app(app) {}

void MainMenuBar::OnAttach()
{
	std::string current_style = GetConfigVariable("GuiStyle");
	menu_variables.styles[current_style] = true;
}

void MainMenuBar::OnRender()
{
	if (ImGui::BeginMainMenuBar())
	{
		if (ImGui::BeginMenu("File"))
    	{
        	if (ImGui::MenuItem("Exit"))
				menu_variables.close_app = true;

        	ImGui::EndMenu();
    	}

		if (ImGui::BeginMenu("Settings"))
    	{
			if (ImGui::BeginMenu("Color Theme"))
			{
				for (auto& color_style : menu_variables.styles)
				{
					if (ImGui::MenuItem(color_style.first.c_str(), "", color_style.second))
					{
						ChangeConfigVariable("GuiStyle", color_style.first);
						UpdateTheme();
						std::for_each(menu_variables.styles.begin(), menu_variables.styles.end(), 
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

	CloseAppPopup(menu_variables.close_app, m_app);
}

void CloseAppPopup(bool& close_app, Application* app)
{
    if (close_app)
		ImGui::OpenPopup("Close the application?");
    
	ImVec2 center = ImGui::GetMainViewport()->GetCenter();
	ImGui::SetNextWindowPos(center, ImGuiCond_Appearing, ImVec2(0.5f, 0.5f));

	if (ImGui::BeginPopupModal("Close the application?", NULL, ImGuiWindowFlags_NoResize))
	{
		ImGui::Text("Are you sure to close the application?\nActive edits will not be saved!\n\n");
		ImGui::Separator();

		if (ImGui::Button("Ok", ImVec2(120, 0)))
			app->m_window->m_running = false;
		ImGui::SameLine();
		if (ImGui::Button("Cancel", ImVec2(120, 0)))
		{
			ImGui::CloseCurrentPopup();
			close_app = false;
		}
			
		ImGui::EndPopup();
	}
}