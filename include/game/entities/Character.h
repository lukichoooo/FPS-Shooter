#pragma once

#include "config/EngineConfig.h"
#include "core/entities/DynamicEntity.h"
#include "game/animation/CharacterAnimator.h"
#include <glm/ext/vector_float3.hpp>

class Character : public DynamicEntity
{
  private:
    CharacterConfig config;
    CharacterAnimator animator;

    float height;


  public:
    Character(const CharacterConfig &config);

    float getHeight() const { return height; }

    void run(glm::vec3 &movement);
    void walk(glm::vec3 &movement);
    void jump();
};
