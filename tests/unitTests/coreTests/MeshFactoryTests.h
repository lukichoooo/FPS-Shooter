#pragma once

#include "core/MeshFactory.h"

class MeshFactoryTests
{
  private:
    static void assertNotNull(void *ptr) { assert(ptr && "Expected non-null pointer"); }
    static void assertNull(void *ptr) { assert(!ptr && "Expected null pointer"); }

  public:
    void test_buildSquare();
    void test_buildCube();
    void test_buildPyramid();
    void test_factoryOverflow();
};

inline void MeshFactoryTests::test_buildSquare()
{
    MeshFactory factory;

    Mesh *m = factory.buildSquare({1, 0, 0, 1});
    assertNotNull(m);

    assert(m->getIndexCount() == 6); // 2 triangles
}

inline void MeshFactoryTests::test_buildCube()
{
    MeshFactory factory;

    Mesh *m = factory.buildCube({0, 1, 0, 1});
    assertNotNull(m);

    assert(m->getIndexCount() == 36); // 12 triangles
}


inline void MeshFactoryTests::test_buildPyramid()
{
    MeshFactory factory;

    Mesh *m = factory.buildPyramid({0, 0, 1, 1});
    assertNotNull(m);

    assert(m->getIndexCount() == 18); // 6 triangles
}


inline void MeshFactoryTests::test_factoryOverflow()
{
    MeshFactory factory;

    Mesh *last = nullptr;
    for (size_t i = 0; i < MeshFactoryConfig::meshesSize; ++i)
    {
        last = factory.buildSquare({1, 1, 1, 1});
        assertNotNull(last);
    }

    // One too many
    Mesh *overflow = factory.buildSquare({1, 0, 1, 1});
    assertNull(overflow);
}

inline void _meshFactoryTests()
{
    MeshFactoryTests sut;
    sut.test_factoryOverflow();
    sut.test_buildCube();
    sut.test_buildPyramid();
    sut.test_buildSquare();
}
