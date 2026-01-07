#include "core/MeshFactory.h"
#include "core/Mesh.h"
#include "game/Engine.h"
#include "config/EngineConfig.h"
#include "game/Scene.h"
#include "core/StaticEntity.h"
#include "graphics/Renderer.h"
#include "core/Camera.h"
#include "core/Input.h"
#include "game/Player.h"
#include "graphics/FrameClock.h"
#include "graphics/Shader.h"
#include <glm/ext/matrix_clip_space.hpp>
#include <glm/ext/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/trigonometric.hpp>

Engine::Engine(const EngineConfig &config)
    : config(config),
      window(config.window),
      renderer(config.render),
      meshBuilder(config.meshFactory) {}


void Engine::run()
{
    Shader shader(config.shader);
    shader.addVertexShader();
    shader.addFragmentShader();
    shader.linkProgram();

    Camera camera(
        config.camera,
        [winPtr = &window](int &w, int &h) { winPtr->getFrameBufferSize(w, h); });
    Player player(config.player);
    Input input(config.input, window.getHandle());


    // glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

    shader.use();
    input.use();

    Mesh *square = meshBuilder.buildSquare();
    Mesh *pyramid = meshBuilder.buildPyramid();

    // Create some entities
    StaticEntity entity1({}, square, &shader);
    StaticEntity entity2({{2.0f, 0.0f, 0.0f}}, pyramid, &shader);
    StaticEntity entity3({{-2.0f, 0.0f, 0.0f}}, square, &shader);

    // Create an array of pointers
    StaticEntity *staticEntities[] = {&entity1, &entity2, &entity3};

    Scene scene;
    scene.setStaticEntities(staticEntities);

    while (!window.windowShouldClose())
    {
        FrameClock::updateDeltaTime();

        input.handleKeyInput(player, camera);
        input.handleMouseSensorInput(camera);

        camera.updateView(player.getCharacter().getPos());
        camera.updateProjection();

        shader.setMat4f("view", camera.getView());
        shader.setMat4f("projection", camera.getProjection());

        renderer.beginFrame();
        renderer.submit(scene);

        window.swapBuffers();
        window.pollEvents();
    }

    window.destroyWindow();
}
