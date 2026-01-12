
#include "game/WorldBuilder.h"
#include "config/EntityConfigs.h"
#include "core/scene/SceneBuilder.h"


Scene WorldBuilder::buildScene(EntityBuilder &eb)
{
    const auto pyramidConfig = config.flyingTarget;
    return SceneBuilder()
        .addStatic(eb.getTerrain())
        // .addDynamic(entityBuilder.getCube(
        //     EntityConfigs::Bigger + Colors::Crimson
        //     + EntityConfigs::PlaceRight))
        .addPyramidTarget(eb.getPyramidTarget(pyramidConfig + EntityConfigs::PlaceAboveLeft + Colors::Gold))
        .addPyramidTarget(eb.getPyramidTarget(pyramidConfig + EntityConfigs::PlaceAboveRight + Colors::Lime))
        .addPyramidTarget(eb.getPyramidTarget(pyramidConfig + EntityConfigs::PlaceSlightlyAbove + Colors::DarkBlue))
        .addPyramidTarget(eb.getPyramidTarget(pyramidConfig + EntityConfigs::PlaceForwardRight + Colors::DarkRed))
        .addPyramidTarget(eb.getPyramidTarget(pyramidConfig + EntityConfigs::PlaceForwardRight + EntityConfigs::PlaceAboveLeft + Colors::Violet))
        .addPyramidTarget(eb.getPyramidTarget(pyramidConfig + EntityConfigs::PlaceAboveLeft + EntityConfigs::PlaceAboveLeft + Colors::DarkGreen))
        .build();
}
