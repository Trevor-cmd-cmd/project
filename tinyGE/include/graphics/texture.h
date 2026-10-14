#pragma once

#include <string>

class Texture
{
    private:
        unsigned int textureID;
    public:
        std::string path;
    
    Texture(const std::string& path);
    void bindTexture();
    void h();
};

