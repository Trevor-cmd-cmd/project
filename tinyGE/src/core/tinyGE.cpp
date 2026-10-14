#include "core/pch.h"
#include "tinyGE.h"
#include "core/object.h"
#include "graphics/camera.h"
#include "graphics/mesh.h"
#include "graphics/shaders.h"
#include "graphics/texture.h"



GLFWwindow* window;
Camera camera{glm::vec3(0.0f, 0.0f, 0.0f)};
Camera cam;
Camera* ac = nullptr;
Shader* as = nullptr;
void tgeInit() 
{
    if(!glfwInit())
    {
        std::cerr << "Failed to initialize GLFW." << std::endl;
        return;
    }
}

void tgeMakewindow(int width, int height, const char* title)
{
    // Create a window with the specified dimensions and title
    window = glfwCreateWindow(width, height, title, nullptr, nullptr);


        glfwMakeContextCurrent(window);
        glfwGetFramebufferSize(window, &width, &height);

        if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
        {
           std::cerr << "Failed to initialize GLAD" << std::endl;
            glfwDestroyWindow(window);
            glfwTerminate();
            return;
        }


        glViewport(0, 0, width, height);
}

void tgeCreateWindow(int width, int height, const char* title)
{
    tgeMakewindow(width, height, title);
}

bool tgeTick() 
{ 
    glfwSwapBuffers(window);
    glfwPollEvents();
    
    //Camera* activeCamera = ac; //!= nullptr ? ac : &camera;
    //glUseProgram(as->shaderProgramm);

    //GLint cameraPosLocation = glGetUniformLocation(as->shaderProgramm, "cameraPos");
    //GLint size = glGetUniformLocation(as->shaderProgramm, "zoom");
    //glUniform1f(size, 0.1f);
    //glUniform3f(cameraPosLocation, activeCamera->position.x, activeCamera->position.y, activeCamera->position.z);
            
        

   return !glfwWindowShouldClose(window); 
}

void tgeShutDown() {}




/**
void tinyGE::init()
{

}

void tinyGE::makewindow(int width, int height, const char* title)
{

}

bool tinyGE::tick()
{

}
*/
/**
{
    
    GLFWwindow* window;
    Camera camera{glm::vec3(0.0f, 0.0f, 0.0f)};
    Camera cam;
    Camera* ac = nullptr;
    Shader* as = nullptr;
    void init()
    {
        if(!glfwInit())
        {
            std::cerr << "Failed to initialize GLFW." << std::endl;
            return;
        }
    }

    void makewindow(int width, int height, const char* title)
    {
        // Create a window with the specified dimensions and title
        window = glfwCreateWindow(width, height, title, nullptr, nullptr);


        glfwMakeContextCurrent(window);
        glfwGetFramebufferSize(window, &width, &height);

        if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
        {
           std::cerr << "Failed to initialize GLAD" << std::endl;
            glfwDestroyWindow(window);
            glfwTerminate();
            return;
        }


        glViewport(0, 0, width, height);
    }

    bool tick()
    {
        glfwSwapBuffers(window);
        glfwPollEvents();


        Camera* activeCamera = ac; //!= nullptr ? ac : &camera;
        glUseProgram(as->shaderProgramm);

        GLint cameraPosLocation = glGetUniformLocation(as->shaderProgramm, "cameraPos");
        GLint size = glGetUniformLocation(as->shaderProgramm, "zoom");
        glUniform1f(size, 0.1f);
        glUniform3f(cameraPosLocation, activeCamera->position.x, activeCamera->position.y, activeCamera->position.z);
            
        

        return !glfwWindowShouldClose(window);
    }
    

}; */
