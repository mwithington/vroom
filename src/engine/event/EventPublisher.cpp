#include "EventPublisher.h"
#include "Event.h"
#include <functional>

EventPublisher::EventPublisher() {
  subscribers = std::vector<std::function<void(Event* event)>>();
}

void EventPublisher::publish(Event* event) {
  for (int i = 0; i < subscribers.size(); i++) {
    subscribers[i](event);
  }
}

void EventPublisher::subscribe(std::function<void(Event* event)> callback) {
  subscribers.push_back(callback);
}
