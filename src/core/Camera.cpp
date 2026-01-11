// #include "spdlog/spdlog.h"


#include "core/pch.hpp"
#include <glm/gtc/quaternion.hpp>
#include <glm/trigonometric.hpp>
#include "core/Camera.h"


Camera::Camera(
    const CameraConfig &config,
    std::function<void(int &, int &)> getFrameBufferSize)

    : config(config),
      FOV(config.defaultFOV),
      front(config.front),
      up(config.up)
{
    getFrameBufferSize(frameBufferWidth, frameBufferHeight);
}


void Camera::updateView(const glm::vec3 &pos)
{
    glm::vec3 direction;
    direction.x = glm::cos(glm::radians(pitch)) * glm::cos(glm::radians(yaw));
    direction.y = glm::sin(glm::radians(pitch));
    direction.z = glm::cos(glm::radians(pitch)) * glm::sin(glm::radians(yaw));
    front = glm::normalize(direction);

#ifdef DEBUG_CAMERA
    spdlog::info("Camera front=({},{},{}), pos=({},{},{})",
        front.x, front.y, front.z, pos.x, pos.y, pos.z);
#endif

    view = glm::lookAt(pos, pos + front, up);
}


void Camera::updateProjection()
{
#ifdef DEBUG_CAMERA
    spdlog::info("Camera Frame buffer w={},h={},Fov={}", frameBufferWidth, frameBufferHeight, FOV);
#endif

    projection = glm::perspective(
        glm::radians(FOV),
        (float)frameBufferWidth / (float)frameBufferHeight,
        config.nearPlane,
        config.farPlane);
}


const glm::vec3 Camera::getYawRotation() const
{
    return glm::vec3(0, -glm::radians(yaw), 0);
}
