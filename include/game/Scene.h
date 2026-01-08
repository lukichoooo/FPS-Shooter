#pragma once

#include "config/EngineConfig.h"
#include "core/entities/StaticEntity.h"
#include "core/entities/DynamicEntity.h"
#include <initializer_list>

// @brief stack allocated static and dynamic entites
class Scene
{
  private:
    StaticEntity staticEntities[SceneConfig::staticEntitiesSize];
    DynamicEntity dynamicEntities[SceneConfig::staticEntitiesSize];
    size_t size_staticEntities{0};
    size_t size_dynamicEntities{0};

  public:
    Scene(
        std::initializer_list<StaticEntity> staticEntities,
        std::initializer_list<DynamicEntity> dynamicEntities);

    void addStaticEntity(const StaticEntity &staticEntity);
    void addEntity(const DynamicEntity &entity);

    std::span<StaticEntity> getStaticEntities()
    {
        return std::span<StaticEntity>(staticEntities, size_staticEntities);
    }

    std::span<DynamicEntity> getDynamicEntities()
    {
        return std::span<DynamicEntity>(dynamicEntities, size_dynamicEntities);
    }
};
