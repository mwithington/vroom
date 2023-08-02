#include "PlayerInputComponent.h"
#include <cmath>
#include <iostream>

PlayerInputComponent::PlayerInputComponent() {}

void PlayerInputComponent::update(Player& player, uint32_t timeElapsed) {
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
    float timestep = (timeElapsed ? timeElapsed : 1) / 1000.0f;
    direction.scale(player.speed * timestep);
    player.pos.mutAdd(direction);
    std::cout << "x:" << player.pos.x << " y:" << player.pos.y << std::endl;
  }

}

void PlayerInputComponent::wrong_update(Player& player, uint32_t timeElapsed) {
  float timestep = (timeElapsed ? timeElapsed : 1) / 1000.0f;
  if(Keyboard::getInstance()->isKeyDown(KEY_W)) {
    player.pos.y += (player.speed * timestep);
  }

  if(Keyboard::getInstance()->isKeyDown(KEY_S)) {
    player.pos.y -= (player.speed * timestep);
  }

  if(Keyboard::getInstance()->isKeyDown(KEY_D)) {
    player.pos.x += (player.speed * timestep);
  }

  if(Keyboard::getInstance()->isKeyDown(KEY_A)) {
    player.pos.x -= (player.speed * timestep);
  }

  std::cout << "x:" << player.pos.x << " y:" << player.pos.y << std::endl;
}
