#pragma once

#include "config/EngineConfig.h"
#include "core/entities/DynamicEntity.h"
#include "game/animation/CharacterAnimator.h"
#include "game/player/PlayerInventory.h"
#include <glm/ext/vector_float3.hpp>

class Character : public DynamicEntity
{
  private:
    CharacterConfig config;
    CharacterAnimator animator;
    PlayerInventory inventory;

    float height;


  public:
    Character(const CharacterConfig &config, const PlayerInventory &inventory);

    float getHeight() const { return height; }

    Gun *getCurrentItem() { return inventory.getCurrentItem(); }

    void run(glm::vec3 &movement);
    void walk(glm::vec3 &movement);
    void jump();

    void selectNextItem();
    void selectPreviousItem();
    void shoot();
    void reload();
    void draw(Shader &shader) override;
};
