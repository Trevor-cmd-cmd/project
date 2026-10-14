#define STB_IMAGE_IMPLEMENTATION
#include "core/pch.h"
#include "graphics/texture.h"

#include <glad/glad.h>
#include "stb/stb_image.h"

Texture::Texture(const std::string& path) : path(path) {}

void Texture::bindTexture()
{
    int width, height, channels;
    stbi_set_flip_vertically_on_load(true);
    unsigned char* imageData = stbi_load(path.c_str(), &width, &height, &channels, 4);
    
    if(imageData)
    {
        glGenTextures(1, &textureID);
        glBindTexture(GL_TEXTURE_2D, textureID);

        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, imageData);
        glGenerateMipmap(GL_TEXTURE_2D);
        stbi_image_free(imageData);

    }
}  

void Texture::h() {
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, textureID);
}