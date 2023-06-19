#include "Board.h"
#include <iostream>

Board::Board() {
  this->width = 0;
  this->height = 0;
  this->tiles = NULL;
}

Board::Board(int width, int height) {
  this->width = width;
  this->height = height;
  this->tiles = new Tile*[width];
  for (int i = 0; i < width; i++) {
    this->tiles[i] = new Tile[height];

    // This will init tiles with the origin being the top left corner
    for (int j = 0; j < height; j++) {
      this->tiles[i][j] = Tile(Vec2(i, j), 0);
    }
  }
}

Board::Board(int width, int height, Tile** tiles) {
  this->width = width;
  this->height = height;
  this->tiles = tiles;
}

void Board::render() {
  std::cout << "render..." << std::endl;
}

void Board::update() {
  std::cout << "update..." << std::endl;
}

void Board::destroy() {
  std::cout << "destroy..." << std::endl;
}

