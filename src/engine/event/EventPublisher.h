#pragma once
#include "Event.h"
#include "Eventful.h"
#include <functional>
#include <utility>
#include <vector>
#include <iostream>

// Consider keeping 10 most recent events
class EventPublisher {
  private:
    std::vector<std::pair<void*, void(*)(void*, Event&)>> subscribers;

  public:
    EventPublisher();
    void publish(Event &event);
    void subscribe(void*, void(*)(void*, Event&));
};
