#include "game/animation/FlyingTargetAnimator.h"

void FlyingTargetAnimator::updatePos(glm::vec3 &pos, const glm::vec3 &inputDir, float speed)
{
    float dt = FrameClock::getDeltaTime();

    glm::vec3 targetVel = inputDir * speed;

    float accelTime = glm::length(targetVel) > glm::length(glm::vec3(velocity.x, 0, velocity.z))
                          ? config.accelerationTime
                          : config.decelerationTime;

    accelTime = glm::max(accelTime, 0.0001f);
    float alpha = glm::min(dt / accelTime, 1.0f);

    velocity.x += (targetVel.x - velocity.x) * alpha;
    velocity.z += (targetVel.z - velocity.z) * alpha;

    pos += velocity * dt;

    if (!onGround)
    {
        if (pos.y <= config.groundY)
        {
            pos.y = config.groundY;
            velocity.y = 0;
            onGround = true;
        }
        else
        {
            velocity.y -= config.gravity * dt;
        }
    }
}


void FlyingTargetAnimator::updatePosBoost(glm::vec3 &pos, const glm::vec3 &inputDir)
{
    updatePos(pos, inputDir, config.boostSpeed);
}

void FlyingTargetAnimator::updatePosFly(glm::vec3 &pos, const glm::vec3 &inputDir)
{
    updatePos(pos, inputDir, config.flySpeed);
}

void FlyingTargetAnimator::drop(const glm::vec3 &pos)
{
    if (pos.y == config.groundY)
    {
        velocity.y = 0;
        onGround = false;
    }
}
