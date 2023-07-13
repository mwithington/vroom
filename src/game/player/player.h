#pragma once

#include "../../engine/entity/entity.h"
#include "../../engine/input/Keyboard.h"
#include "../../engine/event/Event.h"
#include "../../engine/event/Eventful.h"

class Player: public Entity, public Eventful {
  private:
    static void onKeyboardEvent(void* player, Event &event);

  public:
    Player();
    void init() override;
    void update() override;
    void render() override;
    void destroy() override;
};
