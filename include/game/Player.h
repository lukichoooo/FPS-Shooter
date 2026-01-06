
#pragma once

#include "config/EngineConfig.h"
#include "game/entities/Character.h"
#include <glm/ext/vector_float3.hpp>

class Player
{
  private:
    PlayerConfig config;

    Character character;

    float FOVMultiplier{1.0f};

  public:
    Player(const PlayerConfig &config);

    const Character &getCharacter() const { return character; }

    void run(const glm::vec3 &movement) { character.run(movement); }
    void walk(const glm::vec3 &movement) { character.walk(movement); }
};
