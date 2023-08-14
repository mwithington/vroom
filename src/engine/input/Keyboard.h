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
    static Keyboard* getInstance();
    static bool isKeyDown(int key);
    static bool isKeyUp(int key);
    static void setKey(int key, bool value);

    EventPublisher* keyboardEvents;
};
