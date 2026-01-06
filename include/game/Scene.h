#pragma once

#include "game/Entity.h"
#include "game/StaticEntity.h"
#include <span>

class Scene
{
  private:
    std::span<StaticEntity *> staticEntities;
    std::span<Entity *> dynamicEntities;

  public:
    void setDynamicEntities(std::span<Entity *> dynamicEntities)
    {
        this->dynamicEntities = dynamicEntities;
    }
    void setStaticEntities(std::span<StaticEntity *> staticEntities)
    {
        this->staticEntities = staticEntities;
    }

    const std::span<Entity *> &getDynamicEntities() { return dynamicEntities; }
    const std::span<StaticEntity *> &getStaticEntities() { return staticEntities; }
};
