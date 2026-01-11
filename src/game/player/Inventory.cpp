#include "game/player/Inventory.h"


Inventory::Inventory(
    const std::array<Gun, PlayerInventoryConfig::slots> &guns)
{
    this->guns = guns;
}


Gun *Inventory::getCurrentItem() { return &guns[index]; }

void Inventory::selectNext() {}
void Inventory::selectPrevious() {}
