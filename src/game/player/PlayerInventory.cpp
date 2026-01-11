#include "game/player/PlayerInventory.h"


PlayerInventory::PlayerInventory(
    const std::array<Gun, PlayerInventoryConfig::slots> &guns)
{
    this->guns = guns;
}


Gun *PlayerInventory::getCurrentItem() { return &guns[index]; }

void PlayerInventory::selectNext() {}
void PlayerInventory::selectPrevious() {}
