#include "Keyboard.h"

Keyboard* Keyboard::instance = nullptr;

Keyboard::Keyboard() {
  for (int i = 0; i < 348; i++) {
    keys[i] = false;
  }
}

Keyboard* Keyboard::getInstance() {
  if (instance == nullptr) {
    instance = new Keyboard();
  }

  return instance;
}

bool Keyboard::isKeyDown(int key) {
  return instance->keys[key];
}

bool Keyboard::isKeyUp(int key) {
  return !instance->keys[key];
}

void Keyboard::setKey(int key, bool value) {
  instance->keys[key] = value;
}
