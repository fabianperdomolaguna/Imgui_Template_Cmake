#include "imgui.h"

#include "application.h"

Application::Application(std::string window_title)
{
    m_window = std::make_unique<Window>("ImGui - OpenGL Context", 1200, 600);
    m_imgui_context = std::make_unique<ImguiContext>(m_window->m_window);
}

Application::~Application(){};

void Application::Run()
{
    while (m_window->m_running)
    {
        m_window->PreRender();
        m_imgui_context->PreRender();

        if (m_window->m_close_popup)
            m_window->CloseAppPopup();

        for (auto& layer_render : m_layer_stack)
			layer_render->OnRender();

        m_imgui_context->PostRender();
        m_window->PostRender();
    }
}