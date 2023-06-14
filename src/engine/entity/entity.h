#pragma once
#include "src/engine/math/vec2.h"

virtual class Entiy {
  public:
    Vec2 position;
    virtual void update();
    virtual void render();
    virtual void destroy();
};
