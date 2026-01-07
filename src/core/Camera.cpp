// #define DEBUG

#include "core/Camera.h"
// #include "spdlog/spdlog.h"
#include <glm/ext/matrix_clip_space.hpp>
#include <glm/ext/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>


Camera::Camera(const CameraConfig &config,
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

#ifdef DEBUG
    spdlog::info("Camera looking at {},{},{}", front.x, front.y, front.z);
#endif

    view = glm::lookAt(pos, pos + front, up);
}


void Camera::updateProjection()
{
#ifdef DEBUG
    spdlog::info("Camera Frame buffer w={},h={}", frameBufferWidth, frameBufferHeight);
#endif

    projection = glm::perspective(
        glm::radians(FOV),
        (float)frameBufferWidth / (float)frameBufferHeight,
        config.nearPlane,
        config.farPlane);
}
