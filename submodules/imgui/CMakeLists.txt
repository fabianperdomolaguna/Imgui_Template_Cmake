find_package(glfw3 REQUIRED)

add_library(imgui STATIC
   imgui.cpp
   imgui_draw.cpp
   imgui_tables.cpp
   imgui_widgets.cpp
   imgui_demo.cpp
   imgui_impl_glfw.cpp
   imgui_impl_opengl3.cpp
)
	
target_include_directories(imgui PUBLIC
   $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
)
	
target_link_libraries(imgui
   glfw
)