
#include "game/Player.h"
#include "config/EngineConfig.h"

Player::Player(
    const PlayerConfig &config)
    : config(config), character(config.characterConfig) {}
