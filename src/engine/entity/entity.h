#pragma once
#include "../math/Vec2.h"
#include <stdint.h>

class Entity {
  public:
    Vec2 pos;
    virtual void init() = 0;
    virtual void update(double) = 0;
    virtual void render() = 0;
    virtual void destroy() = 0;
};
