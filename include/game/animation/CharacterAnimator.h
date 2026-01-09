#pragma once

#include "config/EngineConfig.h"
#include <GL/glew.h>
#include <glm/geometric.hpp>

// CharacterAnimator handles smoothing and physics
class CharacterAnimator
{
  private:
    CharacterAnimatorConfig config;

    glm::vec3 velocity{};
    bool onGround{true};

    void updatePos(glm::vec3 &pos, const glm::vec3 &inputDir, float speed);


  public:
    CharacterAnimator(const CharacterAnimatorConfig &config) : config(config) {}


    void updatePosRun(glm::vec3 &pos, const glm::vec3 &inputDir);
    void updatePosWalk(glm::vec3 &pos, const glm::vec3 &inputDir);
    void jump(const glm::vec3 &pos);
};
