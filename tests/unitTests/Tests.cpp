#include "coreTests/CameraTests.h"
#include "coreTests/MeshFactoryTests.h"
#include "testsHelper/GLTestContext.h"
#include "unitTests/coreTests/DynamicEntityTests.h"
#include "unitTests/coreTests/StaticEntityTests.h"
#include "unitTests/coreTests/SceneTests.h"
#include "spdlog/spdlog.h"

int main()
{
    GLTestContext::init();

    // core tests
    _dynamicEntityTests();
    _staticEntityTests();
    _meshFactoryTests();
    _cameraTests();

    // game tests
    _sceneTests();

    spdlog::info("ALL TESTS FINISHED SUCCESFULLY");
}
