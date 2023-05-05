#pragma once

#include <string>

#include "GLFW/glfw3.h"

#include "window.h"

class Window
{
    std::string m_title;
    uint16_t m_width;
    uint16_t m_height;

public:
    GLFWwindow* m_window;
    bool m_running = true;
    bool m_close_popup = false;

    Window(std::string title, int32_t width, int32_t height);
    ~Window();

    void PreRender();
    void PostRender();

    void CloseAppPopup();
};