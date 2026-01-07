
#include "game/WorldBuilder.h"
#include "config/Colors.h"
#include "config/EntityConfigs.h"


Scene WorldBuilder::buildScene(Shader *shader)
{
    Mesh *groundMesh = meshFactory.buildSquare(Colors::BrightBlue);
    Mesh *squareMesh = meshFactory.buildSquare(Colors::Black);
    Mesh *pyramidMesh = meshFactory.buildPyramid(Colors::DarkRed);

    return Scene(
        {
            // static entities
            StaticEntity(EntityConfigs::Ground, groundMesh, shader),
            StaticEntity({{-2.0f, 0.0f, 0.0f}}, squareMesh, shader),
            // StaticEntity(EntityConfigs::Big, squareMesh, shader),
            StaticEntity({{2.0f, 0.0f, 0.0f}}, pyramidMesh, shader),
            StaticEntity(EntityConfigs::RotateDown, pyramidMesh, shader),
        },
        {
            // dynamic entities

        });
}
