#pragma once

#include "config/EngineConfig.h"
#include "graphics/FrameClock.h"
#include <GL/glew.h>
#include <glm/geometric.hpp>

// CharacterAnimator handles smoothing and physics
class CharacterAnimator
{
  private:
    CharacterAnimatorConfig config;

    glm::vec3 velocity{};
    bool onGround{true};

    void updatePos(glm::vec3 &pos, const glm::vec3 &inputDir, float speed)
    {
        float dt = FrameClock::getDeltaTime();

        glm::vec3 targetVel = inputDir * speed;

        float accelTime = glm::length(targetVel) > glm::length(glm::vec3(velocity.x, 0, velocity.z))
                              ? config.accelerationTime
                              : config.decelerationTime;

        accelTime = glm::max(accelTime, 0.0001f);
        float alpha = glm::min(dt / accelTime, 1.0f);

        // Horizontal acceleration
        velocity.x += (targetVel.x - velocity.x) * alpha;
        velocity.z += (targetVel.z - velocity.z) * alpha;

        // Integrate position
        pos += velocity * dt;

        // Gravity
        if (!onGround)
        {
            if (pos.y <= config.groundY)
            {
                pos.y = config.groundY;
                velocity.y = config.groundY;
                onGround = true;
            }
            else
            {
                velocity.y -= config.gravity * dt;
            }
        }
    }


  public:
    CharacterAnimator(const CharacterAnimatorConfig &config) : config(config) {}


    void updatePosRun(glm::vec3 &pos, const glm::vec3 &inputDir)
    {
        updatePos(pos, inputDir, config.runSpeed);
    }

    void updatePosWalk(glm::vec3 &pos, const glm::vec3 &inputDir)
    {
        updatePos(pos, inputDir, config.walkSpeed);
    }

    void jump(const glm::vec3 &pos)
    {
        if (pos.y == config.groundY)
        {
            velocity.y = config.jumpVelocity;
            onGround = false;
        }
    }
};
