#include "player.h"
#include <iostream>


Player::Player(unsigned int shaderprogram) {
  std::cout << "creating player" << std::endl;
  inputComponent = PlayerInputComponentFactory::create(PlayerInputComponentType::DUMMY);
  std::cout << "created inputComponent" << std::endl;
  std::cout << "creating renderComponent" << std::endl;
  renderComponent = new PlayerRenderComponent(0, shaderprogram);
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

bool Player::getComponent(Enums::ComponentTypes componentType, void * ptr) {
  switch (componentType) {
    case Enums::ComponentTypes::Render:
      ptr = this->renderComponent;
      break;

    case Enums::ComponentTypes::Input:
      ptr = this->inputComponent;
      break;

    default:
      std::cout << "Not a valid ComponentType: " << componentType << std::endl;
      return false;
  }

  return true;
}
