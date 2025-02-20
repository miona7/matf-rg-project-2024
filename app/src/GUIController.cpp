//
// Created by miona on 2/20/25.
//
#include <engine/graphics/GraphicsController.hpp>
#include <engine/platform/PlatformController.hpp>
#include <GUIController.hpp>
#include <imgui.h>

namespace app {

    void GUIController::initialize() {
        set_enable(false);
    }

    void GUIController::poll_events() {
        auto platform = engine::core::Controller::get<engine::platform::PlatformController>();
        if (platform->key(engine::platform::KEY_F2).state() == engine::platform::Key::State::JustPressed) {
            set_enable(!is_enabled());
        }
    }

    void GUIController::draw() {
        auto graphics = engine::core::Controller::get<engine::graphics::GraphicsController>();
        auto camera = graphics->camera();

        graphics->begin_gui();
        ImGui::Begin("Camera info");
        ImGui::Text("Camera position: (%.2f, %.2f, %.2f)", camera->Position.x, camera->Position.y, camera->Position.z);
        ImGui::End();
        graphics->end_gui();
    }
}

