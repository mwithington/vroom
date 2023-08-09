#include "EventPublisher.h"
#include "Event.h"
#include <functional>

EventPublisher::EventPublisher() {
  // subscribers = std::vector<std::function<void(Event* event)>>();
  subscribers = std::vector<std::pair<void*, void(*)(void*, Event&)>>();
}

void EventPublisher::publish(Event &event) {
  for (int i = 0; i < subscribers.size(); i++) {
    auto fn = subscribers[i].second;
    auto sub = subscribers[i].first;
    // std::cout << "running fn..." << std::endl;
    fn(sub, event);
  }
}

void EventPublisher::subscribe(void* sub, void(*fn)(void*, Event&)) {
  subscribers.push_back(std::pair<void*, void(*)(void*, Event&)>(sub, fn));
}
