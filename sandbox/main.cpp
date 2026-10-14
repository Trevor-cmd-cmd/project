/*#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <vector>
#include <string>

#include "shaders.h"
#include "mesh.h"



int main()
{
    float unitX, unitY;
    int width = 1280;
    int height = 720;
    if (!glfwInit())
    {
        std::cerr << "Failed to initialize GLFW" << std::endl;
        return 1;
    }
    
    GLFWwindow* window = glfwCreateWindow(width, height, "Square", nullptr, nullptr);


    glfwMakeContextCurrent(window);
    glfwGetFramebufferSize(window, &width, &height);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cerr << "Failed to initialize GLAD" << std::endl;
        glfwDestroyWindow(window);
        glfwTerminate();
        return 1;
    }

    unitX = (2.0f) / (16.0f);
    unitY = (2.0f) / (9.0f);

    glViewport(0, 0, width, height);

    std::vector<Vector3> vertices =
    {
        Vector3(0, 0, 0),
        Vector3(1, 0, 0),
        Vector3(0, 1, 0),
        Vector3(1, 1, 0),
    };
    std::vector<unsigned int> indices =
    {
        0, 1, 2,    
        2, 3, 1
    };
    std::vector<Vector3> verticess =
    {
        Vector3(2, 0, 0),
        Vector3(3, 0, 0),
        Vector3(2, 1, 0),
        Vector3(3, 1, 0),
    };


    Mesh mesh(vertices, indices);
    mesh.createMesh();
    Mesh meshs(verticess, indices);
    meshs.createMesh();

    std::string vertexSource = openShader("vertex.glsl");
    std::string fragmentSource = openShader("fragment.glsl");

    
    Shader shader(vertexSource.c_str(), fragmentSource.c_str());
    shader.createShader();
    unsigned int shaderProgram = shader.shaderProgramm;


    while (!glfwWindowShouldClose(window))
    {
        glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glUseProgram(shaderProgram);

        GLint cameraPosLocation = glGetUniformLocation(shaderProgram, "cameraPos");
        glUniform3f(cameraPosLocation, 0.5f, 0.0f, 0.0f);

        meshs.renderMesh();
        mesh.renderMesh();
        
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glDeleteProgram(shaderProgram);
    //glDeleteBuffers(1, &mesh.VBO);
    //glDeleteVertexArrays(1, &mesh.VAO);
    //glDeleteBuffers(1, &mesh.EBO);

    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}
*/