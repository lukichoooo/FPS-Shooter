
#include "game/Scene.h"
#include "spdlog/spdlog.h"


Scene::Scene(
    std::initializer_list<StaticEntity> staticEntities,
    std::initializer_list<DynamicEntity> dynamicEntities)
{
    for (auto &e : staticEntities)
    {
        if (size_staticEntities >= SceneConfig::dynamicEntitiesSize)
        {
            spdlog::error("static entities array full, size={}", size_staticEntities);
            break;
        }
        this->staticEntities[size_staticEntities++] = e;
    }
    for (auto &e : dynamicEntities)
    {
        if (size_staticEntities >= SceneConfig::staticEntitiesSize)
        {
            spdlog::error("dynamic entities array full, size={}", size_staticEntities);
            break;
        }
        this->dynamicEntities[size_dynamicEntities++] = e;
    }
}


void Scene::addStaticEntity(const StaticEntity &entity)
{
    if (size_staticEntities >= SceneConfig::staticEntitiesSize)
    {
        spdlog::error("static entities array full, size={}", size_staticEntities);
        return;
    }
    this->staticEntities[size_staticEntities++] = entity;
}

void Scene::addEntity(const DynamicEntity &entity)
{
    if (size_dynamicEntities >= SceneConfig::dynamicEntitiesSize)
    {
        spdlog::error("dynamic entities array full, size={}", size_dynamicEntities);
        return;
    }
    this->dynamicEntities[size_dynamicEntities++] = entity;
}
