#pragma once

#include "config/EngineConfig.h"
#include "core/Mesh.h"

// @brief stores all meshes on stack
class MeshFactory
{
  private:
    Mesh meshesStorage[MeshFactoryConfig::meshesSize];
    size_t index{};

    Mesh *square;
    Mesh *pyramid;
    Mesh *cube;


  public:
    MeshFactory();

    size_t getNextIndex() { return index; }

    Mesh *getSquare() { return square; }
    Mesh *getPyramid() { return pyramid; }
    Mesh *getCube() { return cube; }

    // @brief creates new instance
    Mesh *buildNewSquare();

    // @brief creates new instance
    Mesh *buildNewPyramid();

    // @brief creates new instance
    Mesh *buildNewCube();
};
