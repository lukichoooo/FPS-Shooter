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

  public:
    Mesh();
    ~Mesh();

    int getVAO() const { return VAO; }
    int getVBO() const { return VBO; }
    int getEBO() const { return EBO; }
    int getIndexCount() const { return indexCount; }

    void bind() { glBindVertexArray(VAO); }

    void clear();
    void createMesh(std::span<Vertex> vertices, std::span<GLuint> indices);
};
