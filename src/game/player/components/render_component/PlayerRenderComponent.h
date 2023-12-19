#pragma once
#include <iostream>
#include <vector>

class Player;
#include "../../player.h"
#include "../../../../engine/graphics/Mesh.h"
#include "../../../../engine/graphics/MeshService.h"
#include "../../../../engine/graphics/RenderService.h"
#include "../../../components/RenderComponent.h"

class PlayerRenderComponent: public RenderComponent {
  public:
    PlayerRenderComponent();
    PlayerRenderComponent(int meshId, unsigned int shaderprogram);
    // void render(Player& player);
};
