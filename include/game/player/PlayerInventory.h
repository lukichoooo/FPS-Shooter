#pragma once

#include "config/EngineConfig.h"
#include "game/entities/Gun.h"

// @brief stores Gun Entities on stack
class PlayerInventory
{
    std::array<Gun, PlayerInventoryConfig::slots> guns;
    int index{};

  public:
    PlayerInventory(const std::array<Gun, PlayerInventoryConfig::slots> &guns);

    Gun *getCurrentItem();
    void selectNext();
    void selectPrevious();
};
