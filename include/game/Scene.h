#pragma once

#include "config/EngineConfig.h"
#include "core/Entity.h"
#include "core/StaticEntity.h"
#include <initializer_list>

// @brief stack allocated static and dynamic entites
class Scene
{
  private:
    StaticEntity staticEntities[SceneConfig::staticEntitiesSize];
    Entity dynamicEntities[SceneConfig::staticEntitiesSize];
    size_t size_staticEntities{0};
    size_t size_dynamicEntities{0};

  public:
    Scene(
        std::initializer_list<StaticEntity> staticEntities,
        std::initializer_list<Entity> dynamicEntities);

    void addStaticEntity(const StaticEntity &staticEntity);
    void addEntity(const Entity &entity);

    std::span<StaticEntity> getStaticEntities()
    {
        return std::span<StaticEntity>(staticEntities, size_staticEntities);
    }

    std::span<Entity> getDynamicEntities()
    {
        return std::span<Entity>(dynamicEntities, size_dynamicEntities);
    }
};
