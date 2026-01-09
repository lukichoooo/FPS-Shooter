#pragma once

#include "config/EngineConfig.h"
#include "core/mesh/Mesh.h"
#include "graphics/Shader.h"

class DynamicEntity
{
  protected:
    EntityConfigStruct config;

    Mesh *mesh;

    glm::vec3 pos;
    glm::vec3 rotation;
    glm::vec3 scale;

    glm::vec4 color{Colors::White};


  public:
    DynamicEntity();
    DynamicEntity(const EntityConfigStruct &config, Mesh *mesh);
    virtual ~DynamicEntity() = default;

    const glm::vec3 &getPos() const { return pos; }
    const glm::vec3 &getRotation() const { return rotation; }
    const glm::vec3 &getScale() const { return scale; }
    const glm::vec4 &getColor() const { return color; };

    void setPos(const glm::vec3 &pos) { this->pos = pos; }
    void setRotation(const glm::vec3 &rotation) { this->rotation = rotation; }
    void setScale(const glm::vec3 &scale) { this->scale = scale; }
    void setColor(glm::vec4 color) { this->color = color; };


    virtual void draw(Shader &shader);
};
