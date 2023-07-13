#pragma once
#include <iostream>
#include "../event/EventPublisher.h"
#include "../event/Event.h"

class Keyboard {
  private:
    bool keys[348];
    static Keyboard* instance;
    Keyboard();

  public:
    // inline static const std::string KEY_DOWN = "KEY_DOWN";
    // inline static const std::string KEY_UP = "KEY_UP";

    static Keyboard* getInstance();
    static bool isKeyDown(int key);
    static bool isKeyUp(int key);
    static void setKey(int key, bool value);

    EventPublisher* keyboardEvents;
};
