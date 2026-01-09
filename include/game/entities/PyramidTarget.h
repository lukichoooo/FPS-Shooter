#pragma once

#include "config/EngineConfig.h"
#include "core/entities/DynamicEntity.h"
#include "game/animation/FlyingTargetAnimator.h"

class PyramidTarget : public DynamicEntity
{
    FlyingTargetConfig config;
    FlyingTargetAnimator animator;

  public:
    PyramidTarget();
    PyramidTarget(const FlyingTargetConfig &config, Mesh *pyramidMesh);

    void fly(glm::vec3 &movement);
    void boost(glm::vec3 &movement);
    void drop();

    void draw(Shader &shader) override;
};
