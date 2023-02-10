cmake_minimum_required(VERSION 3.13)  # CMake version check
project(simple_example)               # Create project "simple_example"
set(CMAKE_CXX_STANDARD 14)            # Enable c++14 standard

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "./out")

# Add main.cpp file of project root directory as source file
set(SOURCE_FILES hello.cpp)

# Add executable target with source files listed in SOURCE_FILES variable
add_executable(simple_example ${SOURCE_FILES})
