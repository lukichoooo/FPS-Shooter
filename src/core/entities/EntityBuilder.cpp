#include "core/entities/EntityBuilder.h"
#include "config/Colors.h"
#include "core/entities/DynamicEntity.h"
#include "config/EntityConfigs.h"
#include "core/entities/StaticEntity.h"

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

PyramidTarget EntityBuilder::getPyramidTarget(const FlyingTargetConfig &config)
{
    return {config, meshFactory.buildNewPyramid()};
}

Gun EntityBuilder::getGun(const GunConfig &config)
{
    return {config, meshFactory.getPistol()};
}


// pre-configured

StaticEntity EntityBuilder::getTerrain()
{
    return {
        EntityConfigs::Ground + Colors::DarkBlue,
        meshFactory.getSquare(),
    };
}

Inventory EntityBuilder::getPlayerInventory(
    const GunConfig &config_1,
    const GunConfig &config_2,
    const GunConfig &config_3)
{
    return {
        {
            getGun(config_1),
            getGun(config_2),
            getGun(config_3),
        }};
}
