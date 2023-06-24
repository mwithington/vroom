#pragma once
#include "../tile/tile.h"
#include "../player/player.h"
#include "../camera/Camera.h"
#include "board/Board.h"

class World {
  private:
    Tile** tiles;
    // TODO: Turn this into a LinkedList
    Board* boards;
    Player* player;
    Camera* camera;

  public:
    World();
    World(Tile** tiles, Board* boards, Player* player);

    void render();
};
