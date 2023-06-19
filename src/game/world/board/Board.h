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
    ~Board();

    void update() override;
    void render() override;
    void destroy() override;
};
