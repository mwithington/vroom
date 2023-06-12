cmake_minimum_required(VERSION 3.13)
project(simple_example)
set(CMAKE_CXX_STANDARD 14)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "./out")

file(GLOB_RECURSE SOURCE_FILES "./src/*.cpp")

add_executable(simple_example ${SOURCE_FILES})

find_package(OpenGL REQUIRED)
include_directories(${OPENGL_INCLUDE_DIR})
set(OpenGL_GL_PREFERENCE STATIC)

include_directories("~/tools/glad/include")
find_package(glfw3 REQUIRED)

target_link_libraries(simple_example PRIVATE glfw GL)
