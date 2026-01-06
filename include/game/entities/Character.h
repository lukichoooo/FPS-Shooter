#pragma once

#include "config/EngineConfig.h"
#include "game/Entity.h"
#include <glm/ext/vector_float3.hpp>

class Character : public Entity
{
  private:
    CharacterConfig config;

    float height;

    float jumpOffset{0.0f};


  public:
    Character(const CharacterConfig &config);

    float getJumpOffset() const { return jumpOffset; }

    void setJumpOffset(float jumpOffset) { this->jumpOffset = jumpOffset; }


    void jump();
    void run(const glm::vec3 &movement);
    void walk(const glm::vec3 &movement);
};
