find_package(OpenGL REQUIRED)
find_package(glfw3 REQUIRED CONFIG)

# ---------- Imgui App --------

add_executable(example
${CMAKE_CURRENT_SOURCE_DIR}/ui_layers/main_menu_bar.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/ui_layers/render_scene.cpp
    main.cpp
)

target_include_directories(example PRIVATE
    ${OPENGL_INCLUDE_DIR}
    "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/ui_layers>"
)

target_link_libraries(example
    #${OPENGL_LIBRARIES}
    #glfw
	#glad
    imgui
    gui_core
)
