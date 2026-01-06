#pragma once

#include "config/EngineConfig.h"
#include "game/Mesh.h"
#include "graphics/Shader.h"
#include <glm/ext/matrix_transform.hpp>

class StaticEntity
{
    EntityConfig config;
    Mesh *mesh;
    Shader *shader;

    glm::mat4 model;

  public:
    StaticEntity(EntityConfig config, Mesh *mesh, Shader *shader);

    void draw() const;
};
