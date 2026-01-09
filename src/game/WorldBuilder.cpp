
#include "game/WorldBuilder.h"
#include "config/EntityConfigs.h"
#include "core/scene/SceneBuilder.h"


Scene WorldBuilder::buildScene()
{
    auto flyingPyramidConfig = config.flyingTarget;
    flyingPyramidConfig = EntityConfigs::PlaceHighAbove + Colors::Crimson;

    return SceneBuilder()
        .addStatic(entityBuilder.getTerrain())
        .addDynamic(entityBuilder.getCube(EntityConfigs::Bigger + Colors::Crimson))
        .addPyramidTarget(entityBuilder.getPyramidTarget(flyingPyramidConfig))
        .build();
}
