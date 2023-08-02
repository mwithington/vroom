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
  return Vec2(this->x + o.x, this->y + o.y);
}

void Vec2::mutAdd(Vec2 o) {
  x += o.x;
  y += o.y;
}

Vec2 Vec2::sub(Vec2 o) {
  return Vec2(this->x - o.x, this->y - o.y);
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
  return (this->x * o.x) + (this->y * o.y);
}

void Vec2::norm() {
  const float len = this->mag();

  this->x = x/len;
  this->y = y/len;
}

Vec2 Vec2::toNorm() {
  const float len = this->mag();

  return Vec2(this->x/len, this->y/len);
}

Vec2 Vec2::operator+(const Vec2 o) {
  return this->add(o);
}

Vec2 Vec2::operator-(const Vec2 o) {
  return this->sub(o);
}

float Vec2::operator*(const Vec2 o) {
  return this->dot(o);
}

float Vec2::mag() {
  return std::sqrt((this->x*this->x) + (this->y*this->y));
}
