#pragma once

#include "config/EngineConfig.h"

class Entity
{
  private:
    EntityConfig config;

    glm::vec3 pos;

    float yVelocity{0.0f};
    bool isInAir{false};


  public:
    Entity(const EntityConfig &config);
    virtual ~Entity() = default;

    const glm::vec3 &getPos() const { return pos; }
    float getYVelocity() const { return yVelocity; }
    bool getIsInAir() const { return isInAir; }

    void setPos(const glm::vec3 &pos) { this->pos = pos; }
    void setYVelocity(float yVelocity) { this->yVelocity = yVelocity; }
    void setIsInAir(bool isInAir) { this->isInAir = isInAir; }

    void move(const glm::vec3 &movement) { pos += movement; }
};
