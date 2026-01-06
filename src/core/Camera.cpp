#include "core/Camera.h"
#include <glm/ext/matrix_clip_space.hpp>
#include <glm/ext/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>


Camera::Camera(const CameraConfig &config)
    : config(config),
      FOV(config.defaultFOV),
      front(config.front),
      up(config.up) {}


void Camera::updateView(const Player &player, SpaceMatrices &matrices)
{
    glm::vec3 direction;
    direction.x = glm::cos(glm::radians(pitch)) * glm::cos(glm::radians(yaw));
    direction.y = glm::sin(glm::radians(pitch));
    direction.z = glm::cos(glm::radians(pitch)) * glm::sin(glm::radians(yaw));
    front = glm::normalize(direction);

    matrices.view = glm::lookAt(player.getPos(), player.getPos() + front, up);
}


void Camera::updateProjection(SpaceMatrices &matrices)
{
    matrices.projection = glm::perspective(
        glm::radians(FOV),
        (float)config.width / (float)config.height, // maybe use framebuffer size?
        config.nearPlane,
        config.farPlane);
}
