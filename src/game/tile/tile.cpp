#include "./tile.h"
#include <iostream>

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

void Tile::render() {
  std::cout << "render..." << std::endl;
}

void Tile::update() {
  std::cout << "update..." << std::endl;
}

void Tile::destroy() {
  std::cout << "destroy..." << std::endl;
}

Vec2 Tile::getPos() {
  return this->pos;
}
