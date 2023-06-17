#include "./tile.h"
#include <iostream>

Tile::Tile() {
  this->pos = Vec2(0, 0);
  this->size = Vec2(1, 1);
  this->type = 0; // default type
}

Tile::Tile(Vec2 pos, Vec2 size, int type) {
  this->pos = pos;
  this->size = size;
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
