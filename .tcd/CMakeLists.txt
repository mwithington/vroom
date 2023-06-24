cmake_minimum_required(VERSION 3.13)
project(vroom)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "../build/out")

file(GLOB_RECURSE SOURCE_FILES "../src/*.cpp")

add_executable(vroom ${SOURCE_FILES})

find_package(OpenGL REQUIRED)
include_directories(${OPENGL_INCLUDE_DIR})
set(OpenGL_GL_PREFERENCE STATIC)

include_directories("C:/tools/glad_attempt_2/include")
include_directories("C:/tools/glfw/glfw-338-64/include")

set(GLFW_LIB_PATH "C:/tools/glfw/glfw-338-64/lib-mingw-w64/libglfw3.a")
set(GLFW_LIB_PATH_2 "C:/tools/glfw/glfw-338-64/lib-mingw-w64/libglfw3dll.a")

target_link_libraries(vroom PRIVATE ${GLFW_LIB_PATH} ${GLFW_LIB_PATH_2} opengl32 )


# Below is building engine as lib and game as executable

# Create engine as static library target
#file(GLOB_RECURSE ENGINE_SOURCE_FILES "./engine/src/*.cpp")
#add_library(engine_lib STATIC
#  ${ENGINE_SOURCE_FILES}
#)

#target_include_directories(engine_lib PUBLIC
#    ${CMAKE_CURRENT_SOURCE_DIR}/engine/include
#)

# External libs
#find_package(OpenGL REQUIRED)
#include_directories(${OPENGL_INCLUDE_DIR})
#set(OpenGL_GL_PREFERENCE STATIC)

#find_package(glfw3 REQUIRED)
#include_directories(${GLFW_INCLUDE_DIR})

# Application
#file(GLOB_RECURSE GAME_SOURCE_FILES "./game/src/*.cpp")

#add_executable(game_app
#  ${GAME_SOURCE_FILES}
#)

# Use when targeting external libs
#set(ENGINE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/libengine_lib.a)
#set(ENGINE_INCLUDE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/engine/include/)
#set(GAME_INCLUDE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/game/include/)

#include_directories($(ENGINE_INCLUDE_PATH))

#target_link_libraries(game_app PRIVATE GL glfw ${ENGINE_PATH})
#target_include_directories(game_app PUBLIC ${ENGINE_INCLUDE_PATH} ${GAME_INCLUDE_PATH})
