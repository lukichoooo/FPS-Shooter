#pragma once

#include "config/EngineConfig.h"
#include "core/Mesh.h"

// @brief stores all meshes on stack
class MeshFactory
{
  private:
    MeshFactoryConfig config;

    std::aligned_storage_t<sizeof(Mesh), alignof(Mesh)>
        storage[MeshFactoryConfig::totalMeshesSize];
    std::span<Mesh> meshes;

    size_t index{};

  public:
    MeshFactory(const MeshFactoryConfig &config);
    Mesh *buildSquare();
    Mesh *buildPyramid();
};
