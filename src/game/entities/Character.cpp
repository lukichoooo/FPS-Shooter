#include "game/entities/Character.h"

Character::Character(const CharacterConfig &config)
    : DynamicEntity(config, nullptr),
      config(config),
      animator(config.animatorConfig),
      height(config.height) {}


void Character::run(glm::vec3 &movement)
{
    animator.updatePosRun(pos, movement);
}

void Character::walk(glm::vec3 &movement)
{
    animator.updatePosWalk(pos, movement);
}

void Character::jump()
{
    animator.jump(pos);
}
