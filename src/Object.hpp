#pragma once
#include <glad/gl.h>
#include <glm/glm.hpp>
#include <vector>
#include "Shader.hpp"

struct Vertex{
    glm::vec3 position;
    glm::vec3 normal;
    glm::vec2 texCoordinates;
    Vertex(const glm::vec3 *positions, const glm::vec2 *texCoordinates) : position(*positions), texCoordinates(*texCoordinates) {};
};


struct Mesh{
    std::vector<Vertex> vertices;
    std::vector<unsigned int> indices;
    unsigned int VAO;
    unsigned int VBO;
    unsigned int EBO;
    explicit Mesh(const std::vector<Vertex> *vertices);
    void draw(Shader &shader);
    void destroy();
};