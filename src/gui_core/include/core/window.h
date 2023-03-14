#pragma once

#include <string>

#include "GLFW/glfw3.h"

class Window
{
    std::string m_title;
    uint16_t m_width;
    uint16_t m_height;

public:
    GLFWwindow* m_window;
    bool m_running = true;

    Window(std::string title, int32_t width, int32_t height);
    ~Window();

    void PreRender();
    void PostRender();
};