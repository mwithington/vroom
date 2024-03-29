#pragma once
#include "../../engine/math/Vec2.h"
#include "../../engine/entity/entity.h"
#include <stdint.h>

class Tile: public Entity {
  private:
    int type;

  public:
    Tile();
    Tile(Vec2 pos, int type);
    ~Tile();
    void init() override;
    void update(double) override;
    void render() override;
    void destroy() override;
    Vec2 getPos();
    void setType(int type);
};
