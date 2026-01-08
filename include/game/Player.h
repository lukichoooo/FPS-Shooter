
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
    Player(const PlayerConfig &config, Camera *camera);

    const Character &getCharacter() const { return character; }

    glm::vec3 getCameraPosition() const;

    void run(glm::vec3 movement);
    void walk(glm::vec3 movement);
    void jump();
};
