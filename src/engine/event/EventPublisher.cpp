#include "EventPublisher.h"
#include "Event.h"

EventPublisher::EventPublisher() {
  std::cout << "This is some real dogshit" << std::endl;
  subscribers = std::vector<std::function<void(Event* event)>>();
  std::cout << "This is some real for the win" << std::endl;
}

void EventPublisher::publish(Event* event) {
  for (int i = 0; i < subscribers.size(); i++) {
    subscribers[i](event);
  }
}

void EventPublisher::subscribe(std::function<void(Event* event)> callback) {
  std::cout << "This is some real making subs man" << std::endl;
  subscribers.push_back(callback);
  std::cout << "This is some real making subs man" << std::endl;
}
