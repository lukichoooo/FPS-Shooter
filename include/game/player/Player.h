
#pragma once

#include "config/EngineConfig.h"
#include "core/Camera.h"
#include "game/entities/Character.h"
#include <glm/ext/vector_float3.hpp>

class Player
{
  private:
    PlayerConfig config;

    Character character;
    Camera *camera;

  public:
    Player(const PlayerConfig &config, PlayerInventory &inventory, Camera *camera);

    Character *getCharacter() { return &character; }

    const glm::vec3 getCameraPosition() const;
    const glm::vec3 &getRotation() const;

    void run(glm::vec3 movement);
    void walk(glm::vec3 movement);
    void jump();
    void setRotation(const glm::vec3 &rotation);

    void selectNextItem();
    void selectPreviousItem();
    void shoot();
    void reload();
};
