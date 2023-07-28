#pragma once
#include <functional>
#include <iostream>

#include "../../engine/entity/entity.h"
#include "../../engine/input/Keyboard.h"
#include "../../engine/input/Keys.h"
#include "../../engine/event/Event.h"
#include "../../engine/event/Eventful.h"

class PlayerInputComponent;
#include "./components/input_component/PlayerInputComponent.h"
#include "./components/input_component/PlayerInputComponentFactory.h"
#include "./components/input_component/PlayerInputComponentConfig.h"

class Player: public Entity, public Eventful {
  private:
    PlayerInputComponent* inputComponent;
    static void onKeyboardEvent(void* player, Event &event);

  public:
    Player();

    float speed;

    // Methods from Entity
    void init() override;
    void update() override;
    void render() override;
    void destroy() override;
};
