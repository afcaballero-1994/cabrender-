#include "Texture.hpp"
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

Texture::Texture(const char *texturePath) {
    int tw, th, nch;
    stbi_set_flip_vertically_on_load(true);
    unsigned char *image = stbi_load(texturePath, &tw, &th, &nch, 0);
    if(!image){
        exit(EXIT_FAILURE);
    }
    glCreateTextures(GL_TEXTURE_2D, 1, &ID);
    //glGenTextures(1, &textureID);
    glBindTexture(GL_TEXTURE_2D, ID);

    glTextureParameteri(ID, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_BORDER);
    glTextureParameteri(ID, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_BORDER);
    glTextureParameteri(ID, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTextureParameteri(ID, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTextureStorage2D(ID, 1, GL_RGB8, tw, th);
    glTextureSubImage2D(ID, 0, 0, 0, tw, th, GL_RGB, GL_UNSIGNED_BYTE, image);
    stbi_image_free(image);
}

void Texture::destroy() {
    glDeleteTextures(1, &ID);
}
