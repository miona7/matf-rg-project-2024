//
// Created by miona on 2/17/25.
//

#ifndef MAINCONTROLLER_HPP
#define MAINCONTROLLER_HPP

#include <engine/core/Controller.hpp>
#include <glm/glm.hpp>
#include <functional>
#include <vector>

namespace app  {

    struct Light {
        glm::vec3 position;
        glm::vec3 color;
        glm::vec3 ambient;
        glm::vec3 direction;
        float c, l, q;
        bool enabled;
    };

    struct Event {
        std::function<void()> action;
        float triggerTime;
        bool triggered;
    };

	class MainController : public engine::core::Controller {

	    Light pointLight;
	    Light dirLight;
	    std::vector<Event> events;

	    glm::vec3 birdPosition;
	    float birdRadius;
	    float birdSpeed;
	    float birdAngle;
	    float birdHeight;
	    bool birdFlying;

	    bool catVisible;
	    bool dogVisible;

	    bool cPressedLastFrame;

        void initialize() override;

        bool loop() override;

	    void updateCamera();

	    void updateEvents(float dt);

	    void updateBird(float dt);

	    void update() override;

	    void drawCar();

	    void drawHouse();

	    void drawBird();

	    void drawDog();

	    void drawCat();

	    void begin_draw() override;

        void drawSkybox();

        void draw() override;

	    void end_draw() override;

        public:
            std::string_view name() const override { return "app::MainController"; }
	};
}

#endif //MAINCONTROLLER_HPP
