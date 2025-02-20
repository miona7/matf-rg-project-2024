//
// Created by miona on 2/17/25.

#include "../include/MyApp.hpp"
#include <MainController.hpp>
#include <spdlog/spdlog.h>

#include "GUIController.hpp"

namespace app {
    void MyApp::app_setup() {
        spdlog::info("App setup completed");
        auto mainController = register_controller<app::MainController>();
        auto guiController = register_controller<app::GUIController>();
        mainController->after(engine::core::Controller::get<engine::core::EngineControllersEnd>());
        mainController->before(guiController);
    }
}
