#pragma once
#include <glad/gl.h>
#include <GLFW/glfw3.h>

struct Display{
    int width;
    int height;
    GLFWwindow *window;
    Display(int width, int height, const char *tile);
    void destroy();
};