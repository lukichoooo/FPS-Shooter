#pragma once

#include "config/EngineConfig.h"
#include "core/Mesh.h"
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


    const glm::mat4 getModel() { return model; }

    void setModel(const glm::mat4 &model) { this->model = model; }

    void draw() const;
};
