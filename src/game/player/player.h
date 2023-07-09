#pragma once

#include "../../engine/entity/entity.h"
#include "../../engine/input/Keyboard.h"
#include "../../engine/event/Event.h"
#include "../../engine/event/Eventful.h"

class Player: public Entity, public Eventful {
  private:
    void onKeyboardEvent(Event* event);

  public:
    Player();
    void update() override;
    void render() override;
    void destroy() override;
};
