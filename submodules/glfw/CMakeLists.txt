include(FetchContent)

FetchContent_Declare(glfw
   GIT_REPOSITORY https://github.com/glfw/glfw
   GIT_TAG        3.3.8
   GIT_SHALLOW    TRUE
)

set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "Build the GLFW example programs")
set(GLFW_BUILD_TESTS OFF CACHE BOOL "Build the GLFW test programs")
set(GLFW_BUILD_DOCS OFF CACHE BOOL "Build the GLFW documentation")
set(GLFW_INSTALL OFF CACHE BOOL "Generate installation target")
  
FetchContent_MakeAvailable(glfw)
