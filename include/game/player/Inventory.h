#pragma once

#include "config/EngineConfig.h"
#include "game/entities/Gun.h"

// @brief stores Gun Entities on stack
class Inventory
{
    std::array<Gun, PlayerInventoryConfig::slots> guns;
    int index{};

  public:
    Inventory(const std::array<Gun, PlayerInventoryConfig::slots> &guns);

    Gun *getCurrentItem();
    void selectNext();
    void selectPrevious();
};
