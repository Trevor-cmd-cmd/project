#include <tinyGE.h>
#include <chrono>
#include "pch.h"
using namespace glm;
 
int main()
{
    tgeInit();
    tgeCreateWindow(800, 600, "window");
    

    Object obj;
    obj.add<Sprite>();
    Mesh a;
    a = Shape::square;

    Shader shader(ShaderType::basic);
    glUseProgram(shader.shaderProgramm);
    Mesh mesh(Shape::square);

    GLint texSamplerLoc = glGetUniformLocation(shader.shaderProgramm, "uTexture");
    GLint zoomLoc = glGetUniformLocation(shader.shaderProgramm, "zoom");
    GLint cameraPosLoc = glGetUniformLocation(shader.shaderProgramm, "cameraPos");

    glUniform1i(texSamplerLoc, 0);
    glUniform1f(zoomLoc, 1.0f);
    glUniform3f(cameraPosLoc, 0.0f, 0.0f, 0.0f);

    glClearColor(0.1f, 0.1f, 0.1f, 1.0f);

    auto* sprite = obj.get<Sprite>();
    // Construct the Mesh directly into the unique_ptr to avoid copying a local Mesh
    
    //sprite->mesh = Shape::square;
    sprite->texture = std::make_unique<Texture>("/home/trevor/Test/tinyGE/assets/happy.png");
    sprite->texture->bindTexture();

    while (tgeTick())
    {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glUseProgram(shader.shaderProgramm);
        glUniform1i(texSamplerLoc, 0);
        glUniform1f(zoomLoc, 1.0f);

        sprite->texture->h();
        //sprite->mesh->render();
    }

    return 0;
}
