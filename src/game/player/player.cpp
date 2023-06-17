#include "./player.h"
#include <iostream>

void Player::update() {
  std::cout << "update..." << std::endl;
}

void Player::render() {
  std::cout << "render..." << std::endl;
}

void Player::destroy() {
  std::cout << "destroy..." << std::endl;
}
