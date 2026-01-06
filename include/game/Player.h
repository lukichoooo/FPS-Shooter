
#pragma once

#include "config/EngineConfig.h"
#include <glm/ext/vector_float3.hpp>

class Player
{
  private:
    float height;
    float jumpStrength;
    float walkSpeed;
    glm::vec3 pos;

    float yVelocity{0.0f};
    bool isJumping{false};
    float jumpOffset{0.0f};

  public:
    Player(const PlayerConfig &config);

    float getWalkSpeed() const { return walkSpeed; }
    const glm::vec3 &getPos() const { return pos; }
    float getYVelocity() const { return yVelocity; }
    float getIsJumping() const { return isJumping; }
    float getJumpOffset() const { return jumpOffset; }

    void setPos(const glm::vec3 &pos) { this->pos = pos; }
    void setYVelocity(float yVelocity) { this->yVelocity = yVelocity; }
    void setIsJumping(bool isJumping) { this->isJumping = isJumping; }
    void setJumpOffset(float jumpOffset) { this->jumpOffset = jumpOffset; }

    void move(const glm::vec3 &delta);
};
