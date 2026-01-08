#include <game/entities/Character.h>

Character::Character(const CharacterConfig &config)
    : DynamicEntity(config, nullptr), // TODO: add body to character
      config(config),
      height(config.height)
{
}


void Character::run(glm::vec3 &movement)
{
    movement.y = jumpYOffset;
    Character::move(movement * config.walkSpeed * config.runSpeedMultiplier);
}

void Character::walk(glm::vec3 &movement)
{
    movement.y = jumpYOffset;
    Character::move(movement * config.walkSpeed);
}

void Character::jump() // TODO
{
}
