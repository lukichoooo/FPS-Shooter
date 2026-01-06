#pragma once

#include "core/Dtos.h"
#include <glm/ext/vector_float4.hpp>
#include <span>
#include <GL/glew.h>

class Mesh
{
  private:
    GLuint VAO, VBO, EBO;
    GLuint indexCount;
    glm::vec4 color;

  public:
    Mesh(std::span<Vertex> vertices, std::span<GLuint> indices, const glm::vec4 &color);
    ~Mesh();

    int getVAO() const { return VAO; }
    int getVBO() const { return VBO; }
    int getEBO() const { return EBO; }
    int getIndexCount() const { return indexCount; }
    const glm::vec4 &getColor() const { return color; };

    void setColor(glm::vec4 color) { this->color = color; };

    void clear();
};
