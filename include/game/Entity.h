#pragma once

#include "config/EngineConfig.h"
#include "game/Mesh.h"
#include "graphics/Shader.h"

class Entity
{
  private:
    EntityConfig config;

    Mesh *mesh;
    Shader *shader;

    glm::vec3 pos;
    glm::vec3 rotation;

    float yVelocity{0.0f};
    bool isInAir{false};


  public:
    Entity(const EntityConfig &config, Mesh *mesh, Shader *shader);
    virtual ~Entity() = default;

    const glm::vec3 &getPos() const { return pos; }
    const glm::vec3 &getRotation() const { return rotation; }
    float getYVelocity() const { return yVelocity; }
    bool getIsInAir() const { return isInAir; }

    void setPos(const glm::vec3 &pos) { this->pos = pos; }
    void setRotation(const glm::vec3 &rotation) { this->rotation = rotation; }
    void setYVelocity(float yVelocity) { this->yVelocity = yVelocity; }
    void setIsInAir(bool isInAir) { this->isInAir = isInAir; }

    void move(const glm::vec3 &movement) { pos += movement; }

    void draw();
};
