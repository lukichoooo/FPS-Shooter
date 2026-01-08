
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

    glm::vec3 getCameraPosition() const
    {
        return character.getPos() + glm::vec3{0.0f, character.getHeight(), 0.0f};
    }

    void run(glm::vec3 movement) { character.run(movement); }
    void walk(glm::vec3 movement) { character.walk(movement); }
};
