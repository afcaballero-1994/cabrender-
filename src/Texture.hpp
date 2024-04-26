#pragma once
#include <glad/gl.h>

struct Texture{
    unsigned int ID;
    Texture(const char *texturePath);
    void destroy();
};