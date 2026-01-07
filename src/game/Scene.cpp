
#include "game/Scene.h"
#include "spdlog/spdlog.h"


Scene::Scene(
    std::initializer_list<StaticEntity> staticEntities,
    std::initializer_list<Entity> dynamicEntities)
{
    for (auto &e : staticEntities)
    {
        if (size_staticEntities >= SceneConfig::dynamicEntitiesSize)
        {
            spdlog::error("static entities array full, size={}", size_staticEntities);
            std::abort();
        }
        this->staticEntities[size_staticEntities++] = e;
    }
    for (auto &e : dynamicEntities)
    {
        if (size_staticEntities >= SceneConfig::staticEntitiesSize)
        {
            spdlog::error("static entities array full, size={}", size_staticEntities);
            std::abort();
        }
        this->dynamicEntities[size_dynamicEntities++] = e;
    }
}


void Scene::addStaticEntity(const StaticEntity &entity)
{
    if (size_staticEntities >= SceneConfig::dynamicEntitiesSize)
    {
        spdlog::error("static entities array full, size={}", size_staticEntities);
        std::abort();
    }
    this->staticEntities[size_staticEntities++] = entity;
}

void Scene::addEntity(const Entity &entity)
{
    if (size_dynamicEntities >= SceneConfig::dynamicEntitiesSize)
    {
        spdlog::error("entities array full, size={}", size_dynamicEntities);
        std::abort();
    }
    this->dynamicEntities[size_dynamicEntities++] = entity;
}
