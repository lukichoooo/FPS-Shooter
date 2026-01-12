#include "game/player/Inventory.h"


Inventory::Inventory(const std::array<Gun, PlayerInventoryConfig::slots> &guns)
{
    this->guns = guns;
}


Gun *Inventory::getCurrentItem() { return &guns[index]; }

void Inventory::selectNext()
{
    const int slots = PlayerInventoryConfig::slots;
    index++;
    index %= slots;
}
void Inventory::selectPrevious()
{
    const int slots = PlayerInventoryConfig::slots;
    index--;
    if (index < 0)
        index += slots;
}
