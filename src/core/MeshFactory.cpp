#define DEBUG

#include "core/MeshFactory.h"
#include "config/Colors.h"
#include "config/EngineConfig.h"
#include "spdlog/spdlog.h"


MeshFactory::MeshFactory(const MeshFactoryConfig &config)
    : config(config) {}

Mesh *MeshFactory::buildSquare()
{
    Vertex vertices[] = {
        {{-1.0, 1.0, 0.0}},
        {{1.0, 1.0, 0.0}},
        {{1.0, -1.0, 0.0}},
        {{-1.0, -1.0, 0.0}},
    };

    GLuint indices[] = {
        0, 1, 3,
        1, 2, 3};

    Mesh *m = new (&storage[index]) Mesh(vertices, indices, Colors::Silver);
    meshes = std::span<Mesh>(reinterpret_cast<Mesh *>(storage), index + 1);

#ifdef DEBUG
    spdlog::info("Built Square at index{}", index);
#endif

    index++;
    return m;
}

Mesh *MeshFactory::buildPyramid()
{
    Vertex vertices[] = {
        {{-1.0, 0.0, 1.0}},
        {{1.0, 1.0, 1.0}},
        {{1.0, 0.0, -1.0}},
        {{0.0, 1.0, 0.0}},
    };

    GLuint indices[] = {
        0, 1, 2,
        0, 1, 3,
        0, 2, 3,
        2, 1, 3};

    Mesh *m = new (&storage[index]) Mesh(vertices, indices, Colors::Silver);
    meshes = std::span<Mesh>(reinterpret_cast<Mesh *>(storage), index + 1);

#ifdef DEBUG
    spdlog::info("Built Pyramid at index{}", index);
#endif

    index++;
    return m;
}
