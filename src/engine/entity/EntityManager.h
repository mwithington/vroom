#pragma once
#include <vector>
#include "./entity.h"

class EntityManager {
  private:
    static EntityManager* instance;
    std::vector<Entity*> entityList;
    EntityManager();

  public:
    static EntityManager* getInstance();
    std::vector<Entity*> getEntityList();
    void addEntity(Entity* e);
    void markForRemoval(Entity* e);
};
