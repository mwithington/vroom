#pragma once
#include "Event.h"
#include "Eventful.h"
#include <functional>
#include <vector>
#include <iostream>

// Consider keeping 10 most recent events
class EventPublisher {
  private:
    std::vector<std::function<void(Event* event)>> subscribers;

  public:
    EventPublisher();
    void publish(Event* event);
    void subscribe(std::function<void(Event* event)> callback);
};
