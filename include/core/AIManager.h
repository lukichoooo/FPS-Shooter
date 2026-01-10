#pragma once

#include "core/scene/Scene.h"
#include "core/scene/Scene.h"
#include "game/player/Player.h"

class AIManager
{
  public:
    void run(Player &player, Scene &scene)
    {
        for (auto &e : scene.getPyramidTargets())
        {
            e.runAI(player.getCameraPosition());
        }
    }
};
