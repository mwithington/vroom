#include "Board.h"

Board::Board() {
  std::cout << "creating board" << std::endl;
  this->width = 0;
  this->height = 0;
  this->tiles = NULL;
  std::cout << "done creating board" << std::endl;
}

Board::Board(int width, int height) {
  this->width = width;
  this->height = height;
  this->tiles = new Tile*[height];
  for (int y = 0; y < height; y++) {
    this->tiles[y] = new Tile[width];
    // This will init tiles with the origin being the top left corner
    for (int x = 0; x < width; x++) {
      this->tiles[y][x] = Tile(Vec2(x, y), 0);
    }
  }
}

Board::Board(int width, int height, Tile** tiles) {
  this->width = width;
  this->height = height;
  this->tiles = tiles;
}

void Board::init() {
  std::cout << "board init" << std::endl;
}

void Board::render() {
  std::cout << "render..." << std::endl;
  std::cout << "yes i am..." << std::endl;
  for (int y = 0; y < height; y++) {
    for (int x = 0; x < width; x++) {
      tiles[y][x].render();
    }
    std::cout << std::endl;
  }
}

void Board::update(double timeElapsed) {
  std::cout << "update..." << std::endl;
}

void Board::destroy() {
  std::cout << "destroy..." << std::endl;
}

Tile** Board::getTiles() {
  return tiles;
}

bool Board::getComponent(Enums::ComponentTypes componentType, void*& ptr) {
  return true;
}

int Board::getArea() {
  return width * height;
}
