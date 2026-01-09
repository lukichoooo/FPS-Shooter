
#include "core/scene/Scene.h"
#include "spdlog/spdlog.h"


void Scene::addStatic(const StaticEntity &entity)
{
    if (index_statics >= statics.size())
    {
        spdlog::error("static entities array full, size={}", index_statics);
        return;
    }
    this->statics[index_statics++] = entity;
}

void Scene::addDynamic(const DynamicEntity &entity)
{
    if (index_dynamics >= dynamics.size())
    {
        spdlog::error("dynamic entities array full, size={}", index_dynamics);
        return;
    }
    this->dynamics[index_dynamics++] = entity;
}

void Scene::addPyramidTarget(const PyramidTarget &entity)
{
    if (index_pyramidTargets >= pyramidTargets.size())
    {
        spdlog::error("pyramidTargets entities array full, size={}", index_dynamics);
        return;
    }
    this->pyramidTargets[index_pyramidTargets++] = entity;
}
