#pragma once

#include "core/scene/Scene.h"
#include "game/entities/PyramidTarget.h"

class SceneBuilder : Scene
{
    Scene scene;

  public:
    Scene &build() { return scene; }

    SceneBuilder &addStatic(const StaticEntity &entity);
    SceneBuilder &addDynamic(const DynamicEntity &entity);
    SceneBuilder &addPyramidTarget(const PyramidTarget &entity);
};
