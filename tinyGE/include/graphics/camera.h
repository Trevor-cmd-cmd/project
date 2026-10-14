#pragma once

#include <glm/glm.hpp>

#include "tinyGE.h"

struct Camera
{
    glm::vec3 position;

    Camera(glm::vec3 pos = {0, 0, 0});
    void UpdateCamera(glm::vec3 pos, const char* name, unsigned int shaderProgram);
    void use();
};
