
#include "core/Scene.h"
#include "spdlog/spdlog.h"


Scene::Scene(
    std::initializer_list<StaticEntity> staticEntities,
    std::initializer_list<DynamicEntity> dynamicEntities)
{
    for (auto &e : staticEntities)
    {
        if (size_statics >= SceneConfig::dynamicEntitiesSize)
        {
            spdlog::error("static entities array full, size={}", size_statics);
            break;
        }
        this->statics[size_statics++] = e;
    }
    for (auto &e : dynamicEntities)
    {
        if (size_statics >= SceneConfig::staticEntitiesSize)
        {
            spdlog::error("dynamic entities array full, size={}", size_statics);
            break;
        }
        this->dynamics[size_dynamics++] = e;
    }
}


void Scene::addStatic(const StaticEntity &entity)
{
    if (size_statics >= SceneConfig::staticEntitiesSize)
    {
        spdlog::error("static entities array full, size={}", size_statics);
        return;
    }
    this->statics[size_statics++] = entity;
}

void Scene::addDynamic(const DynamicEntity &entity)
{
    if (size_dynamics >= SceneConfig::dynamicEntitiesSize)
    {
        spdlog::error("dynamic entities array full, size={}", size_dynamics);
        return;
    }
    this->dynamics[size_dynamics++] = entity;
}
