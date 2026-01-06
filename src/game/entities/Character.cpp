#include <game/entities/Character.h>

Character::Character(const CharacterConfig &config)
    : Entity(config),
      config(config),
      height(config.height) {}


void Character::run(const glm::vec3 &movement)
{
    Character::move(movement * config.runSpeedMultiplier);
}

void Character::walk(const glm::vec3 &movement)
{
    Character::move(movement);
}

void Character::jump() // TODO
{
}
