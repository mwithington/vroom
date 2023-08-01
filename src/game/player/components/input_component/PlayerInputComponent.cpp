#include "PlayerInputComponent.h"
#include <cmath>
#include <iostream>

PlayerInputComponent::PlayerInputComponent() {}

void PlayerInputComponent::update(Player& player) {
  const float speedFun = 0.8f;
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
    player.pos.x += (direction.x * player.speed);
    player.pos.y += (direction.y * player.speed);
    std::cout << "x:" << player.pos.x << " y:" << player.pos.y << std::endl;
  }

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
