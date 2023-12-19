#include "./EntityManager.h"
#include <algorithm>
using namespace Enums;

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

void EntityManager::render() {
  // Sort entityList in tempvar to be in DESC order
  std::vector<Entity*> sortedEntityList = std::vector<Entity*>();
  // std::sort();

  for (size_t i = 0; i < entityList.size(); i++) {
    Entity* tmpEntity = entityList[i];
    RenderComponent* ptr = nullptr;
    tmpEntity->getComponent(Enums::ComponentTypes::Render, ptr);
    ptr->render(*tmpEntity);
  }
  // Highest render prio list
  // Loop through and render
}

void mergeSort(std::vector<Entity*> tmpEnityList) {

}
