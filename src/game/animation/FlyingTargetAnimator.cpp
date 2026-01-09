#include "game/animation/FlyingTargetAnimator.h"
#include "graphics/FrameClock.h"


void FlyingTargetAnimator::updatePos(glm::vec3 &pos)
{
    float dt = FrameClock::getDeltaTime();

    // Increment orbit and spin angles
    orbitAngle += config.orbitSpeed * dt;
    spinAngle += config.spinSpeed * dt;

    // Compute new position based on orbit
    pos.x = config.orbitCenter.x + std::cos(orbitAngle) * config.orbitRadius;
    pos.z = config.orbitCenter.z + std::sin(orbitAngle) * config.orbitRadius;

    // Consider vertical movement
    considerIfDropping(pos);
}


void FlyingTargetAnimator::updatePosDirectedBoost(glm::vec3 &pos, const glm::vec3 &inputDir)
{
    updatePosDirected(pos, inputDir, config.boostSpeed);
}

void FlyingTargetAnimator::updatePosDirectedFly(glm::vec3 &pos, const glm::vec3 &inputDir)
{
    updatePosDirected(pos, inputDir, config.flySpeed);
}

void FlyingTargetAnimator::drop(glm::vec3 &pos)
{
    if (pos.y > config.groundY)
    {
        if (velocity.y >= 0)
            velocity.y = 0;
        dropping = true;
    }
}


// private helper methods


void FlyingTargetAnimator::updatePosDirected(glm::vec3 &pos, const glm::vec3 &inputDir, float speed)
{
    float dt = FrameClock::getDeltaTime();

    glm::vec3 targetVel = inputDir * speed;

    float accelTime = glm::length(targetVel) > glm::length(velocity)
                          ? config.accelerationTime
                          : config.decelerationTime;

    accelTime = glm::max(accelTime, 0.0001f);
    float alpha = glm::min(dt / accelTime, 1.0f);

    velocity += (targetVel - velocity) * alpha;

    pos += velocity * dt;

    considerIfDropping(pos);
}

void FlyingTargetAnimator::considerIfDropping(glm::vec3 &pos)
{
    if (dropping)
    {
        if (pos.y <= config.groundY)
        {
            pos.y = config.groundY;
            velocity.y = 0;
            dropping = false;
        }
        else
        {
            velocity.y -= config.gravity * FrameClock::getDeltaTime();
        }
    }
}
