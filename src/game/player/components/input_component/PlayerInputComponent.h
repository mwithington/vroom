#pragma once

#include "../../../../engine/input/Keyboard.h"
#include "../../../../engine/input/Keys.h"
class Player;
#include "../../player.h"

class PlayerInputComponent {
  public:
    PlayerInputComponent();
    void update(Player& player, uint32_t);
    void wrong_update(Player& player, uint32_t);
};
