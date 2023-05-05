#include <iostream>

#include "pybind11/embed.h"

#include "application.h"
#include "main_menu_bar.h"
#include "render_scene.h"

namespace py = pybind11;

int main()
{	
    std::cout << "[C++] Program started" << std::endl;

    py::scoped_interpreter guard{};
    py::exec(R"(
        print("[Python] Intrepreter says hello!")
    )");

    auto add_module = py::module::import("scripts.add");
    auto add = add_module.attr("add");
    std::cout << "Add result from Python script: " << add(2, 3, 5).cast<int>() << std::endl;

    Application* app = new Application("ImGui - OpenGL Context");

    app->PushLayerApp<MainMenuBar>();
    app->PushLayer<SimpleRender>();

    app->Run();

    delete app;
}