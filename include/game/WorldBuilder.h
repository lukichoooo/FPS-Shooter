#pragma once

#include "config/EngineConfig.h"
#include "core/entities/EntityBuilder.h"
#include "core/scene/Scene.h"

class WorldBuilder
{
    const WorldBuilderConfig &config;

  public:
    WorldBuilder(const WorldBuilderConfig &config) : config(config) {}

    Scene buildScene(EntityBuilder &eb);
};
