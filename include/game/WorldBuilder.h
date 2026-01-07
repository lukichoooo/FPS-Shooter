#pragma once

#include "core/MeshFactory.h"
#include "game/Scene.h"

class WorldBuilder
{
    MeshFactory meshFactory;

  public:
    Scene buildScene(Shader *shader);
};
