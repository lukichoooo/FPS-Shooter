#pragma once

#include "config/EngineConfig.h"
#include <glm/ext/vector_float3.hpp>
#include <glm/geometric.hpp>

class FlyingTargetAnimator
{
  private:
    FlyingTargetAnimatorConfig config;

    // glm::vec3 up;

    glm::vec3 velocity{};
    bool dropping{false};

    float orbitAngleRad{};
    float yaw{};
    float pitch{};

    void updatePosDirected(glm::vec3 &pos, const glm::vec3 &inputDir, float speed);
    void considerIfDropping(glm::vec3 &pos);

  public:
    FlyingTargetAnimator() {}
    FlyingTargetAnimator(const FlyingTargetAnimatorConfig &config) : config(config) {}


    void updatePosDirectedBoost(glm::vec3 &pos, const glm::vec3 &inputDir);
    void updatePosDirectedFly(glm::vec3 &pos, const glm::vec3 &inputDir);

    void updatePos(glm::vec3 &pos);
    void updateRotationDirected(glm::vec3 &rotation, const glm::vec3 &pos, const glm::vec3 &targetPos);

    void drop(glm::vec3 &pos);
};
