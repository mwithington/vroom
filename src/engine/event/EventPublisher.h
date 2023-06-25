#pragma once
#include "Event.h"
#include <vector>

// NOTE: Consider keeping 10 most recent events
class EventPublisher {
  private:
    std::vector<void (*)(Event* event)> subscribers;

  public:
    EventPublisher();
    void publish(Event* event);
    void subscribe(void (*)(Event* event));
};
