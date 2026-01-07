// #define DEBUG

#include "game/Engine.h"
#include "config/EngineConfig.h"
#include "game/Scene.h"
#include "game/WorldBuilder.h"
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
// #include "spdlog/spdlog.h"

Engine::Engine(const EngineConfig &config)
    : config(config),
      window(config.window),
      renderer(config.render),
      worldBuilder() {}


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

    Scene scene = worldBuilder.buildScene(&shader);


    while (!window.windowShouldClose())
    {
        FrameClock::updateDeltaTime();

        input.handleKeyInput(player, camera);
        input.handleMouseSensorInput(camera);

        camera.updateView(player.getCharacter().getPos());
        camera.updateProjection();

        shader.setMat4f("view", camera.getView());
        shader.setMat4f("projection", camera.getProjection());

#ifdef DEBUG
        spdlog::info("begining frame rendering");
#endif
        renderer.beginFrame();
        renderer.submit(scene);

        window.swapBuffers();
        window.pollEvents();
#ifdef DEBUG
        spdlog::info("succesfully rendered frame");
#endif
    }

    window.destroyWindow();
}
