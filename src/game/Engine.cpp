// #define DEBUG_ENGINE

#include "game/Engine.h"
#include "config/EngineConfig.h"
#include "core/AIManager.h"
#include "core/entities/EntityBuilder.h"
#include "core/scene/Scene.h"
#include "game/WorldBuilder.h"
#include "game/player/Inventory.h"
#include "graphics/Renderer.h"
#include "core/Camera.h"
#include "core/Input.h"
#include "game/player/Player.h"
#include "graphics/FrameClock.h"
#include "graphics/Shader.h"

Engine::Engine(const EngineConfig &config)
    : config(config),
      window(config.window),
      renderer(config.render),
      worldBuilder(config.worldBuilder),
      entityBuilder() {}


void Engine::run()
{
    Shader shader(config.shader);
    shader.addVertexShader();
    shader.addFragmentShader();
    shader.linkProgram();

    Camera playerCamera(
        config.camera,
        [winPtr = &window](int &w, int &h) { winPtr->getFrameBufferSize(w, h); });

    GunConfig gun_1_config;
    GunConfig gun_2_config;
    GunConfig gun_3_config;
    Inventory inventory = entityBuilder.getPlayerInventory(
        gun_1_config + Colors::Red,
        gun_2_config + Colors::Green,
        gun_3_config + Colors::Gold);
    Player player(config.player, inventory, &playerCamera);


    // glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

    Input input(config.input, window.getHandle());
    AIManager aiManager;

    shader.use();
    input.use();

    Scene scene = worldBuilder.buildScene(entityBuilder);


    while (!window.windowShouldClose())
    {
        FrameClock::updateDeltaTime();

        input.handleInput(player, playerCamera);

        aiManager.run(player, scene);

        playerCamera.updateView(player.getCameraPosition());
        playerCamera.updateProjection();
        player.setRotation(playerCamera.getYawRotation());

        shader.setMat4f("view", playerCamera.getView());
        shader.setMat4f("projection", playerCamera.getProjection());

#ifdef DEBUG_ENGINE
        spdlog::info("begining frame rendering");
#endif
        renderer.beginFrame();
        renderer.submit(player, shader);
        renderer.submit(scene, shader);

        window.swapBuffers();
        window.pollEvents();
#ifdef DEBUG_ENGINE
        spdlog::info("succesfully rendered frame");
#endif
    }

    window.destroyWindow();
}
