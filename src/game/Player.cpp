#include <game/Player.h>

Player::Player(const PlayerConfig &config)
    : height(config.height),
      jumpStrength(config.jumpStrength),
      walkSpeed(config.walkSpeed),
      pos(config.initialPos) {}

void Player::move(const glm::vec3 &delta)
{
    pos += delta;
}
