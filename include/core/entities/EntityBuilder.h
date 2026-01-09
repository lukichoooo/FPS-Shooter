#pragma once

#include "core/mesh/MeshFactory.h"
#include "core/entities/DynamicEntity.h"
#include "core/entities/StaticEntity.h"
#include "game/entities/PyramidTarget.h"

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
    // getPistol();
    // getHouse();

    // pre-configured
    StaticEntity getTerrain();
};
