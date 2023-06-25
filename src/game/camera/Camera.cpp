#include "Camera.h"
Camera::Camera() {
  this->position = Vec2(0, 0);
  this->size = Vec2(0, 0);
}

Camera::Camera(Vec2 position, Vec2 size) {
  this->position = position;
  this->size = size;
}

void Camera::zoom(float factor) {
  this->size.x += factor;
  this->size.y += factor;
}

void Camera::pan(Vec2 delta) {
  this->position = this->position.add(delta);
}

Vec2 Camera::getSize() {
  return this->size;
}

Vec2 Camera::getPosition() {
  return this->position;
}

