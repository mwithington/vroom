#pragma once

#include "../../engine/entity/entity.h"

class Player: public Entity {
  public:
    void update() override;
    void render() override;
    void destroy() override;
};
