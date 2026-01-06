#pragma once

#include "core/Camera.h"
#include <cassert>
#include <glm/ext/matrix_clip_space.hpp>
#include <glm/ext/matrix_transform.hpp>

class CameraTests
{
  public:
    void updateViewTest();
    void updateProjectionTest();
};

inline void CameraTests::updateViewTest()
{
    CameraConfig config;
    config.width = 100;
    config.height = 200;
    config.defaultFOV = 100;
    config.farPlane = 200;
    config.nearPlane = 20;
    Camera sut(config);

    glm::vec3 direction;
    direction.x = glm::cos(glm::radians(sut.getPitch()))
                  * glm::cos(glm::radians(sut.getYaw()));
    direction.y = glm::sin(glm::radians(sut.getPitch()));
    direction.z = glm::cos(glm::radians(sut.getPitch()))
                  * glm::sin(glm::radians(sut.getYaw()));
    auto front = glm::normalize(direction);


    glm::vec3 pos = {0, 0, 0};

    auto expected = glm::lookAt(
        pos, pos + front, sut.up);

    SpaceMatrices matrices;

    sut.updateView(pos, matrices);

    assert(sut.front == front);
    assert(matrices.view == expected);
}

inline void CameraTests::updateProjectionTest()
{
    CameraConfig config;
    config.width = 100;
    config.height = 200;
    config.defaultFOV = 100;
    config.farPlane = 200;
    config.nearPlane = 20;
    Camera sut(config);

    SpaceMatrices matrices;

    auto expected = glm::perspective(
        glm::radians(config.defaultFOV),
        (float)config.width / (float)config.height,
        config.nearPlane,
        config.farPlane);

    sut.updateProjection(matrices);

    assert(expected == matrices.projection);
}


inline void cameraTests()
{
    CameraTests sut;
    sut.updateViewTest();
    sut.updateProjectionTest();
}
