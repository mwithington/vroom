#pragma once
#include "../../engine/math/Vec2.h"

class Camera {
  private:
    Vec2 size;
    Vec2 position;

  public:
    Camera();
    Camera(Vec2 position, Vec2 size);

    void zoom(float factor);
    void pan(Vec2 delta);

    Vec2 getSize();
    Vec2 getPosition();

    void setSize(Vec2 size);
    void setPosition(Vec2 position);
};


