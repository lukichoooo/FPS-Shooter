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
    config.defaultFOV = 100;
    config.farPlane = 200;
    config.nearPlane = 20;
    float frameBufferWidth = 200;
    float frameBufferHeight = 100;

    Camera sut(config,
        [&frameBufferHeight, &frameBufferWidth](int &w, int &h) {
        w = frameBufferWidth;
        h = frameBufferHeight; });

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

    sut.updateView(pos);

    assert(sut.front == front);
    assert(sut.getView() == expected);
}

inline void CameraTests::updateProjectionTest()
{
    CameraConfig config;
    config.defaultFOV = 100;
    config.farPlane = 200;
    config.nearPlane = 20;
    float frameBufferWidth = 200;
    float frameBufferHeight = 100;

    Camera sut(config,
        [&frameBufferHeight, &frameBufferWidth](int &w, int &h) {
        w = frameBufferWidth;
        h = frameBufferHeight; });

    auto expected = glm::perspective(
        glm::radians(config.defaultFOV),
        (float)frameBufferWidth / (float)frameBufferHeight,
        config.nearPlane,
        config.farPlane);

    sut.updateProjection();

    assert(expected == sut.getProjection());
}


inline void cameraTests()
{
    CameraTests sut;
    sut.updateViewTest();
    sut.updateProjectionTest();
}
