#pragma once

#include "game/Entity.h"
#include <span>

class Scene
{
  private:
    int lastFreeIndex{0};
    std::span<Entity *> entities;

  public:
    Scene(std::span<Entity *> entities);

    const std::span<Entity *> &getEntities() { return entities; }
};
