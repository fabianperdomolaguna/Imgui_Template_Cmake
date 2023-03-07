find_package(OpenGL REQUIRED)
find_package(glfw3 REQUIRED CONFIG)

# ---------- Imgui App --------

add_executable(example main.cpp)

target_include_directories(example PRIVATE
    ${OPENGL_INCLUDE_DIR}
)

target_link_libraries(example
    glfw
	glad
    imgui
)
