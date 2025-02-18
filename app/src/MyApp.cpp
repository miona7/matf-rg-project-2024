//
// Created by miona on 2/17/25.

#include "../include/MyApp.hpp"
#include <MainController.hpp>
#include <spdlog/spdlog.h>

namespace app {
    void MyApp::app_setup() {
        spdlog::info("App setup completed");
        auto mainController = register_controller<app::MainController>();
        mainController->after(engine::core::Controller::get<engine::core::EngineControllersEnd>());
    }
}
