
#include "game/Player.h"
#include "config/EngineConfig.h"

Player::Player(
    const PlayerConfig &config, Camera *camera)
    : config(config),
      character(config.characterConfig),
      camera(camera) {}


glm::vec3 Player::getCameraPosition() const
{
    return character.getPos() + glm::vec3{0.0f, character.getHeight(), 0.0f};
}

void Player::run(glm::vec3 movement)
{
    // camera->setFov(speedFovMultiplier * camera->getFov());
    character.run(movement);
}

void Player::walk(glm::vec3 movement)
{
    character.walk(movement);
}

void Player::jump()
{
    character.jump();
}
