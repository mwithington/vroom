#include "Vec3.h"
#include <iostream>
#include <cmath>

Vec3::Vec3() {
  this->x = 0;
  this->y = 0;
  this->z = 0;
}

Vec3::Vec3(float x, float y, float z) {
  this->x = x;
  this->y = y;
  this->z = z;
}

Vec3 Vec3::add(Vec3 o) {
  return Vec3(this->x + o.x, this->y + o.y, this->z + o.z);
}

Vec3 Vec3::sub(Vec3 o) {
  return Vec3(this->x - o.x, this->y - o.y, this->z - o.z);
}

Vec3 Vec3::cross(Vec3 o) {
  return Vec3(
    (this->y * o.z) - (this->z * o.y),
    (this->z * o.x) - (this->x * o.z),
    (this->x * o.y) - (this->y * o.x)
  );
}

float Vec3::dot(Vec3 o) {
  return (this->x * o.x) + (this->y * o.y) + (this->z * o.z);
}

float Vec3::mag() {
  return sqrt((this->x*this->x) + (this->y*this->y) + (this->z*this->z));
}

void Vec3::norm() {
  const float len = this->mag();

  this->x = x/len;
  this->y = y/len;
  this->z = z/len;
}

Vec3 Vec3::toNorm() {
  const float len = this->mag();

  return Vec3(this->x/len, this->y/len, this->z/len);
}

Vec3 Vec3::operator+(const Vec3 o) {
  return this->add(o);
}

Vec3 Vec3::operator-(const Vec3 o) {
  return this->sub(o);
}

float Vec3::operator*(const Vec3 o) {
  return this->dot(o);
}

Vec3 Vec3::operator^(const Vec3 o) {
  return this->cross(o);
}
