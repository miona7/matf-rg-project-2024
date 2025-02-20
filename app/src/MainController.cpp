//
// Created by miona on 2/18/25.
//

#include <engine/core/Engine.hpp>
#include <engine/graphics/GraphicsController.hpp>
#include "../include/MainController.hpp"
#include <spdlog/spdlog.h>

namespace app {
    void MainController::initialize() {
        spdlog::info("MainController initialized");
    }

    bool MainController::loop() {
        auto platform = engine::core::Controller::get<engine::platform::PlatformController>();
        if (platform->key(engine::platform::KeyId::KEY_ESCAPE).is_down()) {
            return false;
        }
        return true;
    }

    void MainController::drawCube() {
        auto resources = engine::core::Controller::get<engine::resources::ResourcesController>();
        engine::resources::Model* model = resources->model("cube");
        engine::resources::Shader* shader = resources->shader("basic");
        model->draw(shader);
    }

    void MainController::draw() {
        drawCube();
    }

} // namespace app
