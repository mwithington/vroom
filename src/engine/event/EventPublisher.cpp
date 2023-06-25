#include "EventPublisher.h"
#include "Event.h"

EventPublisher::EventPublisher() {
  subscribers = std::vector<void (*)(Event* event)>();
}

void EventPublisher::publish(Event* event) {
  for (int i = 0; i < subscribers.size(); i++) {
    subscribers[i](event);
  }
}

void EventPublisher::subscribe(void (*callback)(Event* event)) {
  subscribers.push_back(callback);
}
