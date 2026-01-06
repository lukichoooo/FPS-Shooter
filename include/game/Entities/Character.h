#pragma once

#include "config/EngineConfig.h"
#include <glm/ext/vector_float3.hpp>

class Character
{
  private:
    PlayerConfig config;

    glm::vec3 pos;
    float height;

    float yVelocity{0.0f};
    bool isJumping{false};
    float jumpOffset{0.0f};
    float FOVMultiplier{1.0f};


    void move(const glm::vec3 &movement) { pos += movement; }

  public:
    Character(const CharacterConfig &config);

    const glm::vec3 &getPos() const { return pos; }
    float getYVelocity() const { return yVelocity; }
    float getIsJumping() const { return isJumping; }
    float getJumpOffset() const { return jumpOffset; }

    void setPos(const glm::vec3 &pos) { this->pos = pos; }
    void setYVelocity(float yVelocity) { this->yVelocity = yVelocity; }
    void setIsJumping(bool isJumping) { this->isJumping = isJumping; }
    void setJumpOffset(float jumpOffset) { this->jumpOffset = jumpOffset; }


    void jump();

    void run(const glm::vec3 &movement);
    void walk(const glm::vec3 &movement);
};
