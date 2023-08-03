#include "./Vec2.h"
#include <iostream>
#include <cmath>

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

void Vec2::transpose(Vec2 vector) {
  std::cout << "transpose..." << std::endl;
}

Vec2 Vec2::add(Vec2 o) {
  return Vec2(x + o.x, y + o.y);
}

void Vec2::mutAdd(Vec2 o) {
  x += o.x;
  y += o.y;
}

Vec2 Vec2::sub(Vec2 o) {
  return Vec2(x - o.x, y - o.y);
}

void Vec2::mutSub(Vec2 o) {
  x -= o.x;
  y -= o.y;
}

void Vec2::scale(float s) {
  x *= s;
  y *= s;
}

float Vec2::dot(Vec2 o) {
  return (x * o.x) + (y * o.y);
}

void Vec2::norm() {
  const float len = this->mag();

  x = x/len;
  y = y/len;
}

Vec2 Vec2::toNorm() {
  const float len = this->mag();

  return Vec2(x/len, y/len);
}

Vec2 Vec2::operator+(const Vec2 o) {
  return add(o);
}

Vec2 Vec2::operator-(const Vec2 o) {
  return sub(o);
}

float Vec2::operator*(const Vec2 o) {
  return dot(o);
}

float Vec2::mag() {
  return std::sqrt((x * x) + (y * y));
}
