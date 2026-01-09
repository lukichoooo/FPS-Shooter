#pragma once

#include "core/entities/EntityBuilder.h"
#include "core/Scene.h"

class WorldBuilder
{
    EntityBuilder entityBuilder;

  public:
    Scene buildScene(Shader &shader);
};
