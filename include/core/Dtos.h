#pragma once

#include <glm/ext/matrix_float4x4.hpp>

struct SpaceMatrices
{
    glm::mat4 model;
    glm::mat4 view;
    glm::mat4 projection;
};

struct Vertex
{
    glm::vec3 position;
};

struct MousePos
{
    double X;
    double Y;
};

struct FrameClock
{
    float lastFrame;
    float deltaTime;
};
