
#include "core/mesh/MeshFactory.h"
#include "spdlog/spdlog.h"

MeshFactory::MeshFactory()
{
    square = buildNewSquare();
    pyramid = buildNewPyramid();
    cube = buildNewCube();
}


Mesh *MeshFactory::buildNewSquare()
{
    if (index >= MeshFactoryStorageConfig::meshesSize)
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

    meshesStorage[index].createMesh(vertices, indices);

#ifdef DEBUG_MESH_FACTORY
    spdlog::info("Built Square stored at index={}", index);
#endif

    return &meshesStorage[index++];
}

Mesh *MeshFactory::buildNewCube()
{
    if (index >= MeshFactoryStorageConfig::meshesSize)
    {
        spdlog::error("MeshFactory storage full!");
        return nullptr;
    }

    Vertex vertices[] = {
        {{0.0, 0.0, 1.0}},
        {{1.0, 0.0, 1.0}},
        {{1.0, 0.0, 0.0}},
        {{0.0, 0.0, 0.0}},

        {{0.0, 1.0, 1.0}},
        {{1.0, 1.0, 1.0}},
        {{1.0, 1.0, 0.0}},
        {{0.0, 1.0, 0.0}},
    };

    GLuint indices[] = {
        // bottom (y = 0)
        0, 1, 3,
        1, 2, 3,

        // top (y = 1)
        4, 5, 7,
        5, 6, 7,

        // front (z = 1)
        0, 1, 4,
        1, 5, 4,

        // back (z = 0)
        3, 2, 7,
        2, 6, 7,

        // left (x = 0)
        0, 3, 4,
        3, 7, 4,

        // right (x = 1)
        1, 2, 5,
        2, 6, 5};


    meshesStorage[index].createMesh(vertices, indices);

#ifdef DEBUG_MESH_FACTORY
    spdlog::info("Built Cube stored at index={}", index);
#endif

    return &meshesStorage[index++];
}


Mesh *MeshFactory::buildNewPyramid()
{
    if (index >= MeshFactoryStorageConfig::meshesSize)
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

    meshesStorage[index].createMesh(vertices, indices);

#ifdef DEBUG_MESH_FACTORY
    spdlog::info("Built Pyramid stored at index={}", index);
#endif

    return &meshesStorage[index++];
}
