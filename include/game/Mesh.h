#pragma once

#include "core/Dtos.h"
#include <GL/glew.h>
#include <span>

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

    void createMesh(std::span<Vertex> vertices, std::span<GLuint> indices);

    void clear();
};
