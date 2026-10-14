#include "core/pch.h"
#include "graphics/camera.h"
#include "core/tinyGE.h"

Camera::Camera(glm::vec3 pos)
    : position(pos) { }

void Camera::UpdateCamera(glm::vec3 pos, const char* name, unsigned int shaderProgram)
{
    position.x = pos.x;
    position.y = pos.y;
    position.z = pos.z;
    GLint location = glGetUniformLocation(shaderProgram, name);
    glUniform3f(location, pos.x, pos.y, pos.z);
}
void Camera::use()
{
    //tinyGE::ac = this;
}