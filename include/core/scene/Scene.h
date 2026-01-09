#pragma once

#include "config/EngineConfig.h"
#include "core/entities/StaticEntity.h"
#include "core/entities/DynamicEntity.h"
#include "game/entities/PyramidTarget.h"
#include <span>

// @brief stack allocated static and dynamic entites
class Scene
{
  private:
    std::array<StaticEntity, SceneStorageConfig::staticEntitiesSize> statics{};
    std::array<DynamicEntity, SceneStorageConfig::dynamicEntitiesSize> dynamics{};
    std::array<PyramidTarget, SceneStorageConfig::pyramidTargetsSize> pyramidTargets;
    size_t index_statics{};
    size_t index_dynamics{};
    size_t index_pyramidTargets{};

  public:
    std::span<StaticEntity> getStaticEntities() { return std::span(statics.data(), index_statics); }
    std::span<DynamicEntity> getDynamicEntities() { return std::span(dynamics.data(), index_dynamics); }
    std::span<PyramidTarget> getPyramidTargets() { return std::span(pyramidTargets.data(), index_pyramidTargets); }


    void addStatic(const StaticEntity &entity);
    void addDynamic(const DynamicEntity &entity);
    void addPyramidTarget(const PyramidTarget &entity);
};
