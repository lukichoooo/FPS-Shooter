#pragma once

#include "core/MeshFactory.h"
#include "core/entities/DynamicEntity.h"
#include "core/entities/StaticEntity.h"

class EntityBuilder
{
  private:
    MeshFactory meshFactory;

  public:
    EntityBuilder();

    // primitives
    DynamicEntity getCube(const EntityConfigStruct &config);
    DynamicEntity getPyramid(const EntityConfigStruct &config);
    DynamicEntity getSquare(const EntityConfigStruct &config);

    // objects
    std::span<DynamicEntity> getPistol();
    std::span<StaticEntity> getHouse();

    // pre-configured
    StaticEntity getTerrain();
};
