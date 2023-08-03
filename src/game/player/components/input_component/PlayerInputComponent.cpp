#include "PlayerInputComponent.h"
#include <algorithm>
#include <cmath>
#include <iostream>

PlayerInputComponent::PlayerInputComponent() {}

void PlayerInputComponent::update(Player& player, double timeElapsed) {
  Vec2 direction = Vec2();
  if(Keyboard::getInstance()->isKeyDown(KEY_W)) {
    direction.y +=1;
  }

  if(Keyboard::getInstance()->isKeyDown(KEY_S)) {
    direction.y -=1;
  }

  if(Keyboard::getInstance()->isKeyDown(KEY_D)) {
    direction.x +=1;
  }

  if(Keyboard::getInstance()->isKeyDown(KEY_A)) {
    direction.x -=1;
  }

  direction.norm();

  if (!std::isnan(direction.mag())) {
    double interval = timeElapsed;
    std::cout << "interval: " << interval << ": timeElapsed" << timeElapsed << std::endl;
    direction.scale(player.speed * interval);
    player.pos.mutAdd(direction);
    std::cout << "x:" << player.pos.x << " y:" << player.pos.y << std::endl;
  }

}

void PlayerInputComponent::wrong_update(Player& player, double timeElapsed) {
  float interval = (timeElapsed ? timeElapsed : 1) / 1000.0f;
  if(Keyboard::getInstance()->isKeyDown(KEY_W)) {
    player.pos.y += (player.speed * interval);
  }

  if(Keyboard::getInstance()->isKeyDown(KEY_S)) {
    player.pos.y -= (player.speed * interval);
  }

  if(Keyboard::getInstance()->isKeyDown(KEY_D)) {
    player.pos.x += (player.speed * interval);
  }

  if(Keyboard::getInstance()->isKeyDown(KEY_A)) {
    player.pos.x -= (player.speed * interval);
  }

  std::cout << "x:" << player.pos.x << " y:" << player.pos.y << std::endl;
}
