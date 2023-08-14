#include "player.h"


Player::Player() {
  std::cout << "creating player" << std::endl;
  inputComponent = PlayerInputComponentFactory::create(PlayerInputComponentType::DUMMY);
  renderComponent = new PlayerRenderComponent(0);
  std::cout << "done creating player" << std::endl;
}

void Player::init() {
  Keyboard::getInstance()->keyboardEvents->subscribe(this, &Player::onKeyboardEvent);
}

void Player::onKeyboardEvent(void* player, Event &event){
  // std::cout << "Ingest Keyboard Event: " << event.type << ":" << event.data;
}

void Player::update(double timeElapsed) {
  inputComponent->update(*this, timeElapsed);
}

void Player::render() {
  std::cout << "render..." << std::endl;
}

void Player::destroy() {
  std::cout << "destroy..." << std::endl;
}
