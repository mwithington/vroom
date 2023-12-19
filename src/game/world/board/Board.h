#pragma once
#include <iostream>
#include "../../../engine/entity/entity.h"
#include "../../tile/tile.h"
#include "../../components/ComponentTypes.h"

class Board: Entity {
  private:
    int width;
    int height;
    Tile** tiles;

  public:
    Board();
    Board(int width, int height);
    Board(int width, int height, Tile** tiles);

    void init() override;
    void update(double) override;
    void render() override;
    void destroy() override;
    bool getComponent(Enums::ComponentTypes componentType, void* ptr) override;
    Tile** getTiles();
};
