#pragma once

#include "config/EngineConfig.h"
#include "core/mesh/MeshFactory.h"
#include "core/entities/DynamicEntity.h"
#include "core/entities/StaticEntity.h"
#include "game/entities/PyramidTarget.h"
#include "game/player/Inventory.h"

class EntityBuilder
{
  private:
    MeshFactory meshFactory;

  public:
    // primitives
    DynamicEntity getCube(const EntityConfigStruct &config);
    DynamicEntity getPyramid(const EntityConfigStruct &config);
    DynamicEntity getSquare(const EntityConfigStruct &config);

    // objects
    PyramidTarget getPyramidTarget(const FlyingTargetConfig &config);
    Gun getGun(const GunConfig &config);
    Inventory getPlayerInventory(
        const GunConfig &config_1,
        const GunConfig &config_2,
        const GunConfig &config_3);

    // getPistol();
    // getHouse();

    // pre-configured
    StaticEntity getTerrain();
};
