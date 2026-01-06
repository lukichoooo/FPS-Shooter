#pragma once

#include "game/Entity.h"
#include <span>

class Scene
{
  public:
    Scene();

    void addEntity(Entity *entity);

  private:
    std::span<Entity *> entities;
};
