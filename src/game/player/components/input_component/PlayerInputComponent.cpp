#include "PlayerInputComponent.h"
#include <iostream>

PlayerInputComponent::PlayerInputComponent() {}

void PlayerInputComponent::update(Player& player) {


}

void PlayerInputComponent::wrong_update(Player& player) {
  if(Keyboard::getInstance()->isKeyDown(KEY_W)) {
    player.pos.y += player.speed;
  }

  if(Keyboard::getInstance()->isKeyDown(KEY_S)) {
    player.pos.y -= player.speed;
  }

  if(Keyboard::getInstance()->isKeyDown(KEY_D)) {
    player.pos.x += player.speed;
  }

  if(Keyboard::getInstance()->isKeyDown(KEY_A)) {
    player.pos.x -= player.speed;
  }

  std::cout << "x:" << player.pos.x << " y:" << player.pos.y << std::endl;
}
