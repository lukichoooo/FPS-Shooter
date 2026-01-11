
#include "game/player/Player.h"
#include "config/EngineConfig.h"

Player::Player(const PlayerConfig &config, PlayerInventory &inventory, Camera *camera)
    : config(config),
      character(config.character, inventory),
      camera(camera) {}


const glm::vec3 Player::getCameraPosition() const
{
    return character.getPos() + glm::vec3{0.0f, character.getHeight(), 0.0f};
}

const glm::vec3 &Player::getRotation() const
{
    return character.getRotation();
}


void Player::run(glm::vec3 movement) { character.run(movement); }
void Player::walk(glm::vec3 movement) { character.walk(movement); }
void Player::jump() { character.jump(); }
void Player::setRotation(const glm::vec3 &rotation) { character.setRotation(rotation); }

void Player::selectNextItem() { character.selectNextItem(); }
void Player::selectPreviousItem() { character.selectPreviousItem(); }
void Player::shoot() { character.shoot(); }
void Player::reload() { character.reload(); }
