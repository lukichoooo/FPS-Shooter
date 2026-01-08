#pragma once

#include "config/EngineConfig.h"
#include <functional>
#include <glm/ext/matrix_float4x4.hpp>

class Camera
{
    friend class CameraTests;

  private:
    CameraConfig config;

    float FOV;
    glm::vec3 front;
    glm::vec3 up;
    int frameBufferWidth;
    int frameBufferHeight;

    glm::mat4 view;
    glm::mat4 projection;

    float yaw{};
    float pitch{};

  public:
    Camera(
        const CameraConfig &config,
        std::function<void(int &, int &)> getFrameBufferSize);

    float getFov() const { return FOV; }
    float getYaw() const { return yaw; }
    float getPitch() const { return pitch; }
    const glm::vec3 &getFront() const { return front; }
    const glm::vec3 &getUp() const { return up; }
    const glm::mat4 &getView() const { return view; }
    const glm::mat4 &getProjection() const { return projection; }

    void setFov(float value) { FOV = value; }
    void setYaw(float value) { yaw = value; }
    void setPitch(float value) { pitch = value; }


    void updateView(const glm::vec3 &pos);
    void updateProjection();
};
