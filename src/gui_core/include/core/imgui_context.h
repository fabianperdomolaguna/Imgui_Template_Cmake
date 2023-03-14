#pragma once

#include "GLFW/glfw3.h"

class ImguiContext
{
public:
    ImguiContext(GLFWwindow* window);
    ~ImguiContext();

    void PreRender();
    void PostRender();
};

void UpdateTheme();
void SetDarkTheme();
void SetLightTheme();