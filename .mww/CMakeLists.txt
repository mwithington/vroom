cmake_minimum_required(VERSION 3.13)
project(vroom)
set(CMAKE_CXX_STANDARD 14)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "../out/bin")

file(GLOB_RECURSE SOURCE_FILES "../src/*.cpp")

add_executable(vroom ${SOURCE_FILES})

find_package(OpenGL REQUIRED)
include_directories(${OPENGL_INCLUDE_DIR})
set(OpenGL_GL_PREFERENCE STATIC)

include_directories("/Users/michael.withington/tools/glad/include")
find_package(glfw3 REQUIRED)

set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -framework OpenGL -framework Cocoa -framework IOKit")
target_link_libraries(vroom PRIVATE glfw)
