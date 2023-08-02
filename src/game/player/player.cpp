#include "player.h"


Player::Player() {
  speed = 5.0f;
  inputComponent = PlayerInputComponentFactory::create(PlayerInputComponentType::DUMMY);
}

void Player::init() {
  Keyboard::getInstance()->keyboardEvents->subscribe(this, &Player::onKeyboardEvent);
}

void Player::onKeyboardEvent(void* player, Event &event){
  // std::cout << "Ingest Keyboard Event: " << event.type << ":" << event.data;
}

void Player::update(uint32_t timeElapsed) {
  inputComponent->update(*this, timeElapsed);
}

void Player::render() {
  std::cout << "render..." << std::endl;
}

void Player::destroy() {
  std::cout << "destroy..." << std::endl;
}
