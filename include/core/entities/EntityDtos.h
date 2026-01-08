#pragma once

#include "core/entities/StaticEntity.h"

struct MapEntity
{
    StaticEntity terrain;

    MapEntity(StaticEntity terrain) : terrain(terrain) {}
};
