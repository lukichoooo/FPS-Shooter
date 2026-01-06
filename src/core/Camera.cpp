#include "core/Camera.h"
#include <glm/ext/matrix_clip_space.hpp>
#include <glm/ext/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>


Camera::Camera(const CameraConfig &config)
    : config(config),
      FOV(config.FOV),
      front(config.front),
      up(config.up)
{
}

void Camera::updateView(const Player &player, SpaceMatrices &matrices) const
{
    matrices.view = glm::lookAt(
        player.getPos(),
        player.getPos() + front,
        up);
}


void Camera::updateProjection(SpaceMatrices &matrices)
{
    matrices.projection = glm::perspective(
        glm::radians(FOV),
        (float)config.width / (float)config.height,
        config.nearPlane,
        config.farPlane);
}
