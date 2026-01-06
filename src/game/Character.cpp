#include "config/EngineConfig.h"
#include <game/Entities/Character.h>

Character::Character(const CharacterConfig &config)
    : config(config),
      pos(config.initialPos),
      height(config.height) {}

void Character::run(const glm::vec3 &movement)
{
    Character::move(movement * config.runSpeedMultiplier);
}

void Character::walk(const glm::vec3 &movement)
{
    Character::move(movement);
}

void Character::jump()
{
}
