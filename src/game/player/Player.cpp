
#include "game/player/Player.h"
#include "config/EngineConfig.h"

Player::Player(const PlayerConfig &config, PlayerInventory &inventory, Camera *camera)
    : config(config),
      inventory(inventory),
      character(config.character),
      camera(camera) {}


glm::vec3 Player::getCameraPosition() const
{
    return character.getPos() + glm::vec3{0.0f, character.getHeight(), 0.0f};
}

void Player::run(glm::vec3 movement) { character.run(movement); }

void Player::walk(glm::vec3 movement) { character.walk(movement); }

void Player::jump() { character.jump(); }

void Player::selectNextItem() { inventory.selectNext(); }

void Player::selectPreviousItem() { inventory.selectPrevious(); }

void Player::shoot() { inventory.getCurrentItem()->shoot(); }
