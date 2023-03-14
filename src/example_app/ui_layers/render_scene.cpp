#include "render_scene.h"

#include "imgui.h"

void SimpleRender::OnRender()
{
    static float clear_color[4] = { 0.45f, 0.55f, 0.60f, 1.00f };
    static float fraction = 0.0f;
    static int counter = 0;

    ImGui::Begin("Render - Slider - Color - FPS");
    ImGui::SliderFloat("Range 0 to 1", &fraction, 0.0f, 1.0f);
    ImGui::ColorEdit3("Color selection", clear_color);

    if (ImGui::Button("Counter"))
        counter++;
    ImGui::SameLine();
    ImGui::Text("You have clicked the button %d times", counter);

    ImGui::Text("Application average - %.3f ms/frame - (%.1f FPS)", 
        1000.0f / ImGui::GetIO().Framerate, 
        ImGui::GetIO().Framerate);
    ImGui::End();

    ImGui::ShowDemoWindow();
}