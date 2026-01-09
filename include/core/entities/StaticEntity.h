#pragma once

#include "config/EngineConfig.h"
#include "core/mesh/Mesh.h"
#include "graphics/Shader.h"
#include <glm/ext/matrix_transform.hpp>

class StaticEntity
{
    EntityConfigStruct config;
    glm::mat4 model;
    Mesh *mesh;

    glm::vec4 color{Colors::White};


  public:
    StaticEntity();
    StaticEntity(EntityConfigStruct config, Mesh *mesh);

    const glm::mat4 &getModel() { return model; }
    const glm::vec4 &getColor() const { return color; };

    void setModel(const glm::mat4 &model) { this->model = model; }
    void setColor(glm::vec4 color) { this->color = color; };

    void draw(Shader &shader) const;
};
