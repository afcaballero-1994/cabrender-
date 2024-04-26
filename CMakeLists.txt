cmake_minimum_required(VERSION 3.27)
project(cabrenderpip)

set(CMAKE_CXX_STANDARD 23)

add_executable(cabrender src/main.cpp
        src/Shader.cpp
        src/Camera.cpp
        src/Display.cpp
        src/Texture.cpp
        src/Object.cpp
        src/Object.hpp
)



add_library(glad includes/glad/gl.h src/gl.c)
target_include_directories(glad PUBLIC includes)


target_link_libraries(cabrender PRIVATE glfw glad)
target_compile_options( cabrender PRIVATE -Wall -pedantic -Wextra -g -fmodules-ts)
