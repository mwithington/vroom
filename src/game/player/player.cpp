#include "./player.h"
#include <functional>
#include <iostream>

Player::Player() {
  // (Player::*)(Event*)
  std::cout << "Player constructor" << std::endl;
  Keyboard::getInstance()->keyboardEvents->subscribe(std::bind(&Player::onKeyboardEvent, this, std::placeholders::_1));
  std::cout << "Player keyboard made" << std::endl;
}

void Player::onKeyboardEvent(Event* event){
  std::cout << "Ingest Keyboard Event: " << event->type << ":" << event->data;
}

void Player::update() {
  std::cout << "update..." << std::endl;
}

void Player::render() {
  std::cout << "render..." << std::endl;
}

void Player::destroy() {
  std::cout << "destroy..." << std::endl;
}
