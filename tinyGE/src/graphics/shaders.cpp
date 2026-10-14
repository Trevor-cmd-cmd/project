#include "core/pch.h"
#include "graphics/shaders.h"
#include "core/tinyGE.h"

#include <filesystem>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

#include <glad/glad.h>
Shader::Shader(ShaderType t)
    : shaderProgramm(0), type(t)
{
    
    createShader();
    //tinyGE::as = this;
}

void Shader::createShader()
{
    int success;
    char infoLog[512];
    auto shaderPaths = getShaderPaths(type);
    auto* vertexShaderS = shaderPaths.vertexPath.c_str();
    auto* fragmentShaderS = shaderPaths.fragmentPath.c_str();
    // add debug log
    
    unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexShaderS, nullptr);
    glCompileShader(vertexShader);

    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(vertexShader, 512, nullptr, infoLog);
        std::cout << infoLog;
    }
    unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderS, nullptr);
    glCompileShader(fragmentShader);

    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(fragmentShader, 512, nullptr, infoLog);
        std::cout << infoLog;
    }

    unsigned int shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
    shaderProgramm = shaderProgram;
}

void checkCompile(){

}

std::string openShader(const std::string& filePath)
{
    
    std::filesystem::path currentFile = __FILE__;
    const std::string h = currentFile.parent_path().parent_path().parent_path().parent_path();;
    std::cout << h +"/tinyGE/assets/shaders/" + filePath << "\n";
    std::ifstream file(h + "/tinyGE/assets/shaders/" + filePath);
    if (file.is_open())
    {
        std::stringstream buffer;
        buffer << file.rdbuf();
        return buffer.str();
    } else { std::cout << "Failed to open shader " << filePath << "\n"; throw;}
    
    return "";
}


ShaderSourcePaths getShaderPaths(ShaderType type) 
{
    switch (type) {
        case ShaderType::basic:
            return { openShader("vertex.glsl"), openShader("fragment.glsl") };
        default:
            return { "", "" };
    }
}

