#include "Human.h"
#include <iostream>


Human::Human() {
  std::cout << "creating human" << std::endl;
}

void Human::init() {
  std::cout << "init..." << std::endl;
}

void Human::update(double timeElapsed) {
  std::cout << "update..." << std::endl;
}

void Human::render() {
  std::cout << "render..." << std::endl;
}

void Human::destroy() {
  std::cout << "destroy..." << std::endl;
}

bool Human::getComponent(Enums::ComponentTypes componentType, void*& ptr) {
  switch (componentType) {
    case Enums::ComponentTypes::Render:
      ptr = this->renderComponent;
      break;

    default:
      std::cout << "Not a valid ComponentType: " << componentType << std::endl;
      return false;
  }

  return true;
}

void Human::setRenderComponent(RenderComponent* component) {
  this->renderComponent = component;
}
