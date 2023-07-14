#include "Keyboard.h"

Keyboard* Keyboard::instance = nullptr;

Keyboard::Keyboard() {
  std::cout << "This is some real horseshit" << std::endl;
  keyboardEvents = new EventPublisher();
  for (int i = 0; i < 348; i++) {
    keys[i] = false;
  }
  std::cout << "This is some real charlie" << std::endl;
}

Keyboard* Keyboard::getInstance() {
  if (instance == nullptr) {
    instance = new Keyboard();
  }
  std::cout << "This is some delta man" << std::endl;

  return instance;
}

bool Keyboard::isKeyDown(int key) {
  return instance->keys[key];
}

bool Keyboard::isKeyUp(int key) {
  return !instance->keys[key];
}

void Keyboard::setKey(int key, bool value) {
  std::cout << "There is no way this is breaking" << std::endl;
  instance->keys[key] = value;
  Event* event = new Event{ key, value ? Keyboard::KEY_DOWN : Keyboard::KEY_UP };
  std::cout << "We are even after then thing" << std::endl;
  instance->keyboardEvents->publish(event);
  delete event;
}
