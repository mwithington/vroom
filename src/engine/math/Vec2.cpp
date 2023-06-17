#include "./Vec2.h"
#include <iostream>

Vec2::Vec2() {
  this->x = 0;
  this->y = 0;
}

Vec2::Vec2(float x, float y) {
  this->x = x;
  this->y = y;
}

void Vec2::transpose(float x, float y) {
  std::cout << "transpose..." << std::endl;
}

void transpose(Vec2 vector) {
  std::cout << "transpose..." << std::endl;
}
