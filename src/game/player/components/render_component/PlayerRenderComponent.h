#pragma once
#include <iostream>
#include <vector>

class Player;
#include "../../player.h"
#include "../../../../engine/graphics/Mesh.h"
#include "../../../../engine/graphics/MeshService.h"
#include "../../../../engine/graphics/RenderService.h"

class PlayerRenderComponent {
  private:
    Mesh* mesh;
    std::vector<float> vertices;

  public:
    PlayerRenderComponent();
    PlayerRenderComponent(int meshId);
    void render(Player& player, unsigned int shaderprogram);
};
