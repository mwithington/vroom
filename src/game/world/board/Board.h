#pragma once
#include "../../../engine/entity/entity.h"
#include "../../tile/tile.h"

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
    Tile** getTiles();
};
