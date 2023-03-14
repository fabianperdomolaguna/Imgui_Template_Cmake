#include "application.h"

#include "main_menu_bar.h"
#include "render_scene.h"

int main()
{	
    Application* app = new Application("ImGui - OpenGL Context");

    app->PushLayerApp<MainMenuBar>();
    app->PushLayer<SimpleRender>();

    app->Run();

    delete app;
}