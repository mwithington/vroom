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
