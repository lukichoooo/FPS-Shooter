
#pragma once

#include "config/EngineConfig.h"
#include "core/Camera.h"
#include "game/player/PlayerInventory.h"
#include "game/entities/Character.h"
#include <glm/ext/vector_float3.hpp>

class Player
{
  private:
    PlayerConfig config;
    PlayerInventory inventory;

    Character character;
    Camera *camera;

  public:
    Player(const PlayerConfig &config, PlayerInventory &inventory, Camera *camera);

    const Character &getCharacter() const { return character; }

    void selectNextItem();
    void selectPreviousItem();
    void shoot();

    glm::vec3 getCameraPosition() const;

    void run(glm::vec3 movement);
    void walk(glm::vec3 movement);
    void jump();
};
