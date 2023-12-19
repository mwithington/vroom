#pragma once
#include <functional>
#include <iostream>

#include "../../engine/entity/entity.h"
#include "../../engine/input/Keyboard.h"
#include "../../engine/input/Keys.h"
#include "../../engine/event/Event.h"
#include "../../engine/event/Eventful.h"
#include "../components/ComponentTypes.h"

class PlayerRenderComponent;
#include "./components/render_component/PlayerRenderComponent.h"

class PlayerInputComponent;
#include "./components/input_component/PlayerInputComponent.h"
#include "./components/input_component/PlayerInputComponentFactory.h"
#include "./components/input_component/PlayerInputComponentConfig.h"

class Player: public Entity, public Eventful {
  private:
    // Variables
    PlayerInputComponent* inputComponent;
    PlayerRenderComponent* renderComponent;

    // Static Methods
    static void onKeyboardEvent(void* player, Event &event);

  public:
    // Ctor
    Player(unsigned int shaderprogram);

    //Variables
    float speed;

    // Methods from Entity
    void init() override;
    void update(double) override;
    void render() override;
    void destroy() override;

    bool getComponent(Enums::ComponentTypes, void*) override;
};
