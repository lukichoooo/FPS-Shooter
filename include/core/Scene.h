#pragma once

#include "config/EngineConfig.h"
#include "core/entities/StaticEntity.h"
#include "core/entities/DynamicEntity.h"
#include <initializer_list>

// @brief stack allocated static and dynamic entites
class Scene
{
  private:
    StaticEntity statics[SceneConfig::staticEntitiesSize];
    DynamicEntity dynamics[SceneConfig::staticEntitiesSize];
    size_t size_statics{0};
    size_t size_dynamics{0};

  public:
    Scene(std::initializer_list<StaticEntity> staticEntities,
        std::initializer_list<DynamicEntity> dynamicEntities);


    std::span<StaticEntity> getStaticEntities()
    {
        return std::span(statics, size_statics);
    }

    std::span<DynamicEntity> getDynamicEntities()
    {
        return std::span(dynamics, size_dynamics);
    }


    void addStatic(const StaticEntity &staticEntity);
    void addDynamic(const DynamicEntity &dynamicEntity);
};
