#include "./tile.h"
#include <iostream>
#include <stdint.h>

Tile::Tile() {
  this->pos = Vec2();
  this->type = 0; // default type
}

Tile::Tile(Vec2 pos, int type) {
  this->pos = pos;
  this->type = type;
}

Tile::~Tile() {
}

void Tile::init() {
  std::cout << "tile init" << std::endl;
}

void Tile::render() {
  std::cout << type;
}

void Tile::update(double timeElapsed) {
  std::cout << "update..." << std::endl;
}

void Tile::destroy() {
  std::cout << "destroy..." << std::endl;
}

Vec2 Tile::getPos() {
  return this->pos;
}

void Tile::setType(int type) {
  this->type = type;
}

void Tile::setRenderComponent(RenderComponent* component) {
  this->renderComponent = component;
}

bool Tile::getComponent(Enums::ComponentTypes componentType, void*& ptr) {
  switch (componentType) {
    case Enums::ComponentTypes::Render:
      ptr = this->renderComponent;

      std::cout << "ptr..." << ptr << std::endl;

      if (this->renderComponent == nullptr) {
        std::cout << "no render cpt?" << std::endl;
        return false;
      }

      std::cout << "got tile render cpt..." << std::endl;
      break;

    case Enums::ComponentTypes::Input:
      // ptr = this->inputComponent;
      if (ptr == nullptr) {
        std::cout << "no input cpt?" << std::endl;
        return false;
      }
      std::cout << "got tile input cpt..." << std::endl;
      break;

    default:
      std::cout << "Not a valid ComponentType: " << componentType << std::endl;
      return false;
  }

  return true;
}
