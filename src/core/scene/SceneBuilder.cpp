#include "core/scene/SceneBuilder.h"


SceneBuilder &SceneBuilder::addStatic(const StaticEntity &staticEntity)
{
    scene.addStatic(staticEntity);
    return *this;
}

SceneBuilder &SceneBuilder::addDynamic(const DynamicEntity &dynamicEntity)
{
    scene.addDynamic(dynamicEntity);
    return *this;
}

SceneBuilder &SceneBuilder::addPyramidTarget(const PyramidTarget &entity)
{
    scene.addPyramidTarget(entity);
    return *this;
}
