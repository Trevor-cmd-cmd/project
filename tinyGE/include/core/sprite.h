#pragma once

#include <memory>

#include "tinyGE.h"
#include "component.h"
#include "mesh.h"
#include "texture.h"

class Sprite : public Component 
{
    public:
        std::unique_ptr<Texture> texture;
        std::unique_ptr<Mesh> mesh = std::unique_ptr<Mesh>();

};