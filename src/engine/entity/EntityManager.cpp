#include "./EntityManager.h"

EntityManager::EntityManager() {
  this->entityList = std::vector<Entity*>();
  this->removalList = std::vector<Entity*>();
}

EntityManager* EntityManager::instance = nullptr;

EntityManager* EntityManager::getInstance() {
  if (instance == nullptr) {
    instance = new EntityManager();
  }

  return instance;
}

std::vector<Entity*> EntityManager::getEntityList() {
  return this->entityList;
}

void EntityManager::addEntity(Entity* e) {
  this->entityList.push_back(e);
}

void EntityManager::markForRemoval(Entity* e) {
  this->removalList.push_back(e);
}

void EntityManager::update(double timeElapsed) {
  // update
  for (int i = 0; i < entityList.size(); i++) {
    entityList.at(i)->update(timeElapsed);
  }

  // remove stale refs
  for (int i = 0; i < removalList.size(); i++) {
    for (int j = entityList.size() - 1; j >= 0; j--) {
      if (removalList.at(i) == entityList.at(j)) {
        entityList.erase(entityList.begin() + j - 1); // TODO(Tom): not sure about the minus 1
      }
    }
  }
  // Loop through removal list and destroy entities
  for (int i = 0; i < removalList.size(); i++) {
    removalList.at(i)->destroy();
  }
  removalList.clear();
}
