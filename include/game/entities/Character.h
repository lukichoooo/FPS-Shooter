#pragma once

#include "config/EngineConfig.h"
#include "core/entities/DynamicEntity.h"
#include <glm/ext/vector_float3.hpp>

class Character : public DynamicEntity
{
  private:
    CharacterConfig config;

    float height;

    float jumpYOffset{0.0f};


  public:
    Character(const CharacterConfig &config);

    float getJumpYOffset() const { return jumpYOffset; }
    float getHeight() const { return height; }

    void setJumpYOffset(float jumpOffset) { this->jumpYOffset = jumpOffset; }


    void jump();
    void run(glm::vec3 &movement);
    void walk(glm::vec3 &movement);
};
