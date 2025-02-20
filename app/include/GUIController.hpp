//
// Created by miona on 2/20/25.
//

#ifndef GUICONTROLLER_HPP
#define GUICONTROLLER_HPP
#include <engine/core/Controller.hpp>

namespace app {
    class GUIController : public engine::core::Controller {

        void initialize() override;

        void draw() override;

    public:
        std::string_view name() const override {
            return "app::GUIController";
        }
    };

} // namespace app

#endif
