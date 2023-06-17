#pragma once
#include "../math/Vec2.h"

class Entity {
  public:
    Vec2 pos;
    virtual void update() = 0;
    virtual void render() = 0;
    virtual void destroy() = 0;
};
