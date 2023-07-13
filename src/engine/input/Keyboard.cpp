#include "Keyboard.h"

Keyboard* Keyboard::instance = nullptr;

Keyboard::Keyboard() {
  for (int i = 0; i < 348; i++) {
    keys[i] = false;
  }

  this->keyboardEvents = new EventPublisher();
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
  if (key < 0 || key > 347) {
    std::cout << "invalid key: " << key << std::endl;
    return;
  }
  instance->keys[key] = value;
  Event event = Event{ key, value ? "key_down" : "key_up" };
  std::cout << "publishing event" << std::endl;
  instance->keyboardEvents->publish(event);
}
