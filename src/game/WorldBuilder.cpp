
#include "game/WorldBuilder.h"
#include "config/EntityConfigs.h"
#include "core/scene/SceneBuilder.h"


Scene WorldBuilder::buildScene()
{
    // auto flyingPyramidConfig = config.flyingTarget;

    return SceneBuilder()
        .addStatic(entityBuilder.getTerrain())
        // .addDynamic(entityBuilder.getCube(
        //     EntityConfigs::Bigger + Colors::Crimson
        //     + EntityConfigs::PlaceRight))
        .addPyramidTarget(entityBuilder.getPyramidTarget(config.flyingTarget + EntityConfigs::PlaceAboveLeft + Colors::Gold))
        .addPyramidTarget(entityBuilder.getPyramidTarget(config.flyingTarget + EntityConfigs::PlaceAboveRight + Colors::Lime))
        .build();
}
