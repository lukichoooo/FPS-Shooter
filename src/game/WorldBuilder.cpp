
#include "game/WorldBuilder.h"
#include "config/EntityConfigs.h"
#include "core/scene/SceneBuilder.h"


Scene WorldBuilder::buildScene(EntityBuilder &eb)
{
    return SceneBuilder()
        .addStatic(eb.getTerrain())
        // .addDynamic(entityBuilder.getCube(
        //     EntityConfigs::Bigger + Colors::Crimson
        //     + EntityConfigs::PlaceRight))
        .addPyramidTarget(eb.getPyramidTarget(config.flyingTarget + EntityConfigs::PlaceAboveLeft + Colors::Gold))
        .addPyramidTarget(eb.getPyramidTarget(config.flyingTarget + EntityConfigs::PlaceAboveRight + Colors::Lime))
        .build();
}
