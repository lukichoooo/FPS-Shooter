
#include "game/WorldBuilder.h"
#include "config/EntityConfigs.h"
#include "core/scene/SceneBuilder.h"


Scene WorldBuilder::buildScene()
{
    return SceneBuilder()
        .addStatic(entityBuilder.getTerrain())
        .addDynamic(entityBuilder.getCube(EntityConfigs::Bigger + Colors::Crimson))
        .addPyramidTarget(entityBuilder.getPyramidTarget(config.flyingTarget))
        .build();
}
