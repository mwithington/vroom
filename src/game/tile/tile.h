#pragma once
#include "../../engine/math/Vec2.h"
#include "../../engine/entity/entity.h"
#include "../components/ComponentTypes.h"
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
    bool getComponent(Enums::ComponentTypes componentType, void*& ptr) override;

    Vec2 getPos();
    void setType(int type);

};
