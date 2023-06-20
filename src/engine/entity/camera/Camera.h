#pragma once
#include "../entity.h"
#include "../EntityManager.h"

class Camera : Entity {
  private:
    float scale;
    EntityManager* entityManager;

  public:
    Camera(EntityManager* entityManager);
    void render() override;
};
