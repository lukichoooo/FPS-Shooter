#include "game/animation/FlyingTargetAnimator.h"
#include "graphics/FrameClock.h"
#include <glm/ext/quaternion_transform.hpp>
#include <glm/ext/vector_float3.hpp>
#include <glm/gtc/constants.hpp>
#include <glm/trigonometric.hpp>


void FlyingTargetAnimator::updatePos(glm::vec3 &pos)
{
    float dt = FrameClock::getDeltaTime();

    orbitAngleRad += config.orbitSpeed * dt;

    if (orbitAngleRad > glm::two_pi<float>())
        orbitAngleRad -= glm::two_pi<float>();

    pos.x += std::cos(orbitAngleRad) * config.orbitRadius;
    pos.z += std::sin(orbitAngleRad) * config.orbitRadius;

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


// TODO fix
void FlyingTargetAnimator::updateRotationDirected(
    glm::vec3 &rotation,
    const glm::vec3 &pos,
    const glm::vec3 &targetPos)
{
    glm::vec3 delta = targetPos - pos;
    if (glm::length(delta) < 0.0001f)
        return;

    glm::vec3 desired;
    desired.y = std::atan2(delta.x, delta.z);
    desired.x = std::atan2(delta.y, glm::length(glm::vec2(delta.x, delta.z)));
    desired.z = 0.0f;

    float step = config.rotationSpeed * FrameClock::getDeltaTime();

    rotation.x = glm::mix(rotation.x, desired.x, step);
    rotation.y = glm::mix(rotation.y, desired.y, step);
    rotation.z = 0.0f;
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
    if (!dropping)
        return;

    float dt = FrameClock::getDeltaTime();

    velocity.y -= config.gravity * dt;

    pos.y += velocity.y * dt;

    if (pos.y <= config.groundY)
    {
        pos.y = config.groundY;
        velocity.y = 0;
        dropping = false;
    }
}
