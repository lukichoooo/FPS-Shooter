#pragma once

#include "config/EngineConfig.h"
#include "core/Dtos.h"
#include "game/Player.h"

class Camera
{
  private:
    float FOV = 90.0f;

    float yaw{};
    float pitch{};

    glm::vec3 front;
    glm::vec3 up;

    CameraConfig config;

  public:
    Camera(const CameraConfig &config);

    float getFOV() const { return FOV; }
    float getYaw() const { return yaw; }
    float getPitch() const { return pitch; }
    const glm::vec3 &getFront() const { return front; }
    const glm::vec3 &getUp() const { return up; }

    void setFOV(float value) { FOV = value; }
    void setYaw(float value) { yaw = value; }
    void setPitch(float value) { pitch = value; }

    void updateView(const Player &player, SpaceMatrices &matrices) const;
    void updateProjection(SpaceMatrices &matrices);
};
