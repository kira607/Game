cmake_minimum_required(VERSION 3.1)
project(Roguelike)

find_package(OpenGL REQUIRED)
find_package(GLEW REQUIRED)

add_subdirectory(glfw)

include_directories(glfw/include)
include_directories(glm)

add_executable(Roguelike src/main.cpp)

target_link_libraries(Roguelike glfw ${OPENGL_LIBRARY} ${GLFW_LIBRARIES} ${GLEW_LIBRARIES})
