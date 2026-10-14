#pragma once

#include <glm/glm.hpp>
#include <vector>


enum class Shape { null, square, };

struct Vertex
{
    glm::vec3 position;
    glm::vec2 uv;

    Vertex(glm::vec3 pos, glm::vec2 uv = {0, 0})
        : position(pos), uv(uv) {}
};
class Mesh
{
    
    private:    
        unsigned int VAO, VBO, EBO;    
        
    public:
        std::vector<Vertex> vertices;
        std::vector<unsigned int> indices;
        Shape type;
    
    Mesh(Shape t = Shape::null);//const std::vector<Vertex>& verts, const std::vector<unsigned int>& inds);
    
    Mesh& operator=(Shape t) {
    *this = Mesh(t);
    return *this;
    }
    //~Mesh();
    void create();
    void upload();
    void render();
};

struct ShapeMesh 
{
    std::vector<Vertex> verts;
    std::vector<unsigned int> inds;
};
ShapeMesh getShapeMesh(Shape type);