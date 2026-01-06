#include <game/Player.h>

Player::Player(const PlayerConfig &config)
    : config(config),
      pos(config.initialPos),
      height(config.height) {}

void Player::run(const glm::vec3 &movement)
{
    Player::move(movement * config.runSpeedMultiplier);
}

void Player::walk(const glm::vec3 &movement)
{
    Player::move(movement);
}

void Player::jump()
{
}
