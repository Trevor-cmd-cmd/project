#include "core/pch.h"
#include "graphics/mesh.h"

#include <glad/glad.h>

using namespace glm;

//Vertex::Vertex(glm::vec3 pos, glm::vec2 uv) : position(pos), uv(uv) {}


Mesh::Mesh(Shape t)
    : type(t), VAO(0), VBO(0), EBO(0) 
    { 
        
        create(); 
    }


void Mesh::create()
{
    
    auto h = getShapeMesh(type);
    vertices = h.verts;
    indices = h.inds;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);

    glBindVertexArray(VAO);
    
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    
    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(Vertex), vertices.data(), GL_DYNAMIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(unsigned int), indices.data(), GL_DYNAMIC_DRAW);

    // position
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    // uv
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    glBindVertexArray(0);
}

void Mesh::render()
{
    glBindVertexArray(VAO);
    glDrawElements(GL_TRIANGLES, indices.size(), GL_UNSIGNED_INT, 0);
}


void Mesh::upload()
{
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferSubData(GL_ARRAY_BUFFER, 0, static_cast<GLsizeiptr>(vertices.size() * sizeof(Vertex)), vertices.data());
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}

ShapeMesh getShapeMesh(Shape type)
{
    std::vector<Vertex> quadVerts = {
        Vertex({-0.5f, -0.5f, 0.0f}, {0.0f, 0.0f}),
        Vertex({ 0.5f, -0.5f, 0.0f}, {1.0f, 0.0f}),
        Vertex({-0.5f,  0.5f, 0.0f}, {0.0f, 1.0f}),
        Vertex({ 0.5f,  0.5f, 0.0f}, {1.0f, 1.0f})
    };
    std::vector<unsigned int> quadInds = { 0, 1, 2, 2, 1, 3 };

    
    switch (type) {
        case Shape::square:
            return { quadVerts, quadInds};
        default:
            return { };
    }
};
//enum class Shape 
//{
//    square,
//};