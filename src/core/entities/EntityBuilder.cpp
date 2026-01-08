#include "core/entities/EntityBuilder.h"
#include "config/Colors.h"
#include "core/entities/DynamicEntity.h"
#include "config/EntityConfigs.h"
#include "core/entities/StaticEntity.h"

EntityBuilder::EntityBuilder() {}

// primitives
DynamicEntity EntityBuilder::getCube(const EntityConfigStruct &config)
{
    return {config, meshFactory.getCube()};
}

DynamicEntity EntityBuilder::getPyramid(const EntityConfigStruct &config)
{
    return {config, meshFactory.getPyramid()};
}

DynamicEntity EntityBuilder::getSquare(const EntityConfigStruct &config)
{
    return {config, meshFactory.getSquare()};
}

// objects
std::span<DynamicEntity> getPistol();
std::span<StaticEntity> getHouse();

// pre-configured

StaticEntity EntityBuilder::getTerrain()
{
    return {
        EntityConfigs::Ground + Colors::DarkBlue,
        meshFactory.getSquare(),
    };
}
