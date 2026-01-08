
#include "game/WorldBuilder.h"
#include "config/Colors.h"
#include "config/EntityConfigs.h"


Scene WorldBuilder::buildScene([[maybe_unused]] Shader &shader)
{


    return Scene(
        {
            // static entities

            entityBuilder.getTerrain(),
        },
        {
            // dynamic entities

            entityBuilder.getPyramid(EntityConfigs::Big + Colors::BrightRed),
        });
}
