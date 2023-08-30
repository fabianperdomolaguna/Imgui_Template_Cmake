#pragma once

#include <string>
#include <vector>
#include <memory>
#include <functional>
#include <any>

#include "window.h"
#include "imgui_context.h"
#include "layer.h"

class Application
{
    std::unique_ptr<ImguiContext> m_imgui_context;
    std::vector<std::shared_ptr<Layer>> m_layer_stack;

public:
    std::unique_ptr<Window> m_window;
    std::function<void()> m_menubar;

    Application(std::string window_title);
    ~Application();
    
    void Run();

    template<typename T, typename... Args>
    void PushLayer(Args&&... args)
    {
        static_assert(std::is_base_of<Layer, T>::value, "Pushed type is not subclass of Layer!");
        m_layer_stack.emplace_back(std::make_shared<T>(std::forward<Args>(args)...))->OnAttach();
    };

    template<typename T>
    void PushLayerApp()
    {
        static_assert(std::is_base_of<Layer, T>::value, "Pushed type is not subclass of Layer!");
        m_layer_stack.emplace_back(std::make_shared<T>(this))->OnAttach();
    };
};