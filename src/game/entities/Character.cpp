#include "game/entities/Character.h"
#include "game/player/Inventory.h"
#include <glm/ext/matrix_transform.hpp>

Character::Character(const CharacterConfig &config, const Inventory &inventory)
    : DynamicEntity(config, nullptr),
      config(config),
      animator(config.animatorConfig),
      inventory(inventory),
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

void Character::selectNextItem() { inventory.selectNext(); }

void Character::selectPreviousItem() { inventory.selectPrevious(); }

void Character::shoot() { inventory.getCurrentItem()->shoot(); }
void Character::reload() { inventory.getCurrentItem()->reload(); }

void Character::draw(Shader &shader)
{
    Gun *item = inventory.getCurrentItem();

    float yaw = rotation.y;

    glm::mat4 itemRot = glm::rotate(glm::mat4(1), yaw, glm::vec3(0, 1, 0));
    glm::vec3 handOffsetGlobal = glm::vec3(itemRot * glm::vec4(config.handOffsetLocal, 0));

    item->setPos(getPos() + handOffsetGlobal);
    item->setRotation(rotation);
    item->draw(shader);

    // DynamicEntity::draw(shader);
}
