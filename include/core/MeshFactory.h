#pragma once

#include "config/EngineConfig.h"
#include "core/Mesh.h"

// @brief stores all meshes on stack
class MeshFactory // TODO: Write tests
{
  private:
    Mesh meshesStorage[MeshFactoryConfig::meshesSize];
    size_t index{};

  public:
    Mesh *buildSquare(const glm::vec4 &color);
    Mesh *buildPyramid(const glm::vec4 &color);
    Mesh *buildCube(const glm::vec4 &color);
};
