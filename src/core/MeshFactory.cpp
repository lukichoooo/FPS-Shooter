#define DEBUG

#include "core/MeshFactory.h"
#include "spdlog/spdlog.h"


Mesh *MeshFactory::buildSquare(const glm::vec4 &color)
{
    if (index >= MeshFactoryConfig::meshesSize)
    {
        spdlog::error("MeshFactory storage full!");
        return nullptr;
    }

    Vertex vertices[] = {
        {{0.0, 0.0, 1.0}},
        {{1.0, 0.0, 1.0}},
        {{1.0, 0.0, 0.0}},
        {{0.0, 0.0, 0.0}},
    };

    GLuint indices[] = {
        0, 1, 3,
        1, 2, 3};

    meshesStorage[index].createMesh(vertices, indices, color);

#ifdef DEBUG
    spdlog::info("Built Square stored at index={}", index);
#endif

    return &meshesStorage[index++];
}


Mesh *MeshFactory::buildPyramid(const glm::vec4 &color)
{
    if (index >= MeshFactoryConfig::meshesSize)
    {
        spdlog::error("MeshFactory storage full!");
        return nullptr;
    }

    Vertex vertices[] = {
        {{0.0, 0.0, 0.0}},
        {{1.0, 0.0, 0.0}},
        {{1.0, 0.0, 1.0}},
        {{0.0, 0.0, 1.0}},

        {{0.5, 1.0, 0.5}},
    };


    GLuint indices[] = {
        0, 1, 2, 0, 2, 3,

        0, 1, 4,
        1, 2, 4,
        2, 3, 4,
        3, 0, 4};

    meshesStorage[index].createMesh(vertices, indices, color);

#ifdef DEBUG
    spdlog::info("Built Pyramid stored at index={}", index);
#endif

    return &meshesStorage[index++];
}
