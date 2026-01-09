#pragma once

#include "config/EngineConfig.h"
#include "graphics/FrameClock.h"
#include <glm/geometric.hpp>

class FlyingTargetAnimator
{
  private:
    FlyingTargetAnimatorConfig config;

    glm::vec3 velocity{};
    bool onGround{true};

    void updatePos(glm::vec3 &pos, const glm::vec3 &inputDir, float speed);

  public:
    FlyingTargetAnimator(const FlyingTargetAnimatorConfig &config) : config(config) {}


    void updatePosBoost(glm::vec3 &pos, const glm::vec3 &inputDir);
    void updatePosFly(glm::vec3 &pos, const glm::vec3 &inputDir);
    void drop(const glm::vec3 &pos);
};
