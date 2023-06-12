cmake_minimum_required(VERSION 3.13)
project(simple_example)
set(CMAKE_CXX_STANDARD 14)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "./out")

file(GLOB_RECURSE SOURCE_FILES "./src/*.cpp")

add_executable(simple_example ${SOURCE_FILES})

find_package(OpenGL REQUIRED)
include_directories(${OPENGL_INCLUDE_DIR})
set(OpenGL_GL_PREFERENCE STATIC)

include_directories("C:/tools/glad_attempt_2/include")
include_directories("C:/tools/glfw/glfw-338-64/include")

set(GLFW_LIB_PATH "C:/tools/glfw/glfw-338-64/lib-mingw-w64/libglfw3.a")
set(GLFW_LIB_PATH_2 "C:/tools/glfw/glfw-338-64/lib-mingw-w64/libglfw3dll.a")

target_link_libraries(simple_example PRIVATE ${GLFW_LIB_PATH} ${GLFW_LIB_PATH_2} opengl32 )
