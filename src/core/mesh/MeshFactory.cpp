
#include "core/mesh/MeshFactory.h"
#include "spdlog/spdlog.h"

MeshFactory::MeshFactory()
{
    square = buildNewSquare();
    pyramid = buildNewPyramid();
    cube = buildNewCube();
    pistol = buildNewPistol();
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


Mesh *MeshFactory::buildNewPistol()
{
    if (index >= MeshFactoryStorageConfig::meshesSize)
    {
        spdlog::error("MeshFactory storage full!");
        return nullptr;
    }

    // Simple pistol: grip + slide (two boxes merged)
    Vertex vertices[] = {
        // --- grip ---
        {{0.0f, 0.0f, 0.0f}}, // 0
        {{0.3f, 0.0f, 0.0f}}, // 1
        {{0.3f, 0.8f, 0.0f}}, // 2
        {{0.0f, 0.8f, 0.0f}}, // 3
        {{0.0f, 0.0f, 0.3f}}, // 4
        {{0.3f, 0.0f, 0.3f}}, // 5
        {{0.3f, 0.8f, 0.3f}}, // 6
        {{0.0f, 0.8f, 0.3f}}, // 7

        // --- slide ---
        {{0.0f, 0.8f, 0.05f}}, // 8
        {{1.0f, 0.8f, 0.05f}}, // 9
        {{1.0f, 1.0f, 0.05f}}, // 10
        {{0.0f, 1.0f, 0.05f}}, // 11
        {{0.0f, 0.8f, 0.25f}}, // 12
        {{1.0f, 0.8f, 0.25f}}, // 13
        {{1.0f, 1.0f, 0.25f}}, // 14
        {{0.0f, 1.0f, 0.25f}}, // 15
    };

    GLuint indices[] = {
        // grip cube
        0, 1, 3, 1, 2, 3,
        4, 5, 7, 5, 6, 7,
        0, 1, 4, 1, 5, 4,
        3, 2, 7, 2, 6, 7,
        0, 3, 4, 3, 7, 4,
        1, 2, 5, 2, 6, 5,

        // slide cube
        8, 9, 11, 9, 10, 11,
        12, 13, 15, 13, 14, 15,
        8, 9, 12, 9, 13, 12,
        11, 10, 15, 10, 14, 15,
        8, 11, 12, 11, 15, 12,
        9, 10, 13, 10, 14, 13};

    meshesStorage[index].createMesh(vertices, indices);

#ifdef DEBUG_MESH_FACTORY
    spdlog::info("Built Pistol stored at index={}", index);
#endif

    return &meshesStorage[index++];
}
