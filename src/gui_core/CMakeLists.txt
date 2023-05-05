find_package(glfw3 REQUIRED CONFIG)

add_library(gui_core STATIC 
   core/window.cpp
   core/application.cpp
   core/imgui_context.cpp
   renderer/texture.cpp
   utilities/image.cpp
   utilities/settings_config.cpp
)

target_include_directories(gui_core PUBLIC
  "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/core>"
  "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/renderer>"
  "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/utilities>"
  "$<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/submodules/stb_image>"
)

target_link_libraries(gui_core
  glfw
  glad
  imgui
  nlohmann_json::nlohmann_json
)

file(COPY ConfigFile.json DESTINATION ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})