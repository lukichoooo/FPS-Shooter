#include "coreTests/CameraTests.h"
#include "coreTests/MeshFactoryTests.h"
#include "testsHelper/GLTestContext.h"
#include "spdlog/spdlog.h"
#include "unitTests/coreTests/EntityTests.h"
#include "unitTests/coreTests/StaticEntityTests.h"
#include "unitTests/gameTests/SceneTests.h"

int main()
{
    GLTestContext::init();

    // core tests
    _entityTests();
    _staticEntityTests();
    _meshFactoryTests();
    _cameraTests();

    // game tests
    _sceneTests();

    spdlog::info("ALL TESTS FINISHED SUCCESFULLY");
}
