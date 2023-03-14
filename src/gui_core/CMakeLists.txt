find_package(glfw3 REQUIRED CONFIG)

add_library(gui_core STATIC 
   core/window.cpp
   core/application.cpp
   core/imgui_context.cpp
   utilities/settings_config.cpp
)

target_include_directories(gui_core PUBLIC
  "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/core>"
  "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/utilities>"
)

target_link_libraries(gui_core
  glfw
  glad
  nlohmann_json::nlohmann_json
  imgui
)

file(COPY ConfigFile.json DESTINATION ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})