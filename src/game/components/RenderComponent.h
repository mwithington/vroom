#pragma once
#include <iostream>
#include <vector>

#include "../../engine/entity/entity.h"
#include "../../engine/graphics/Mesh.h"
#include "../../engine/graphics/MeshService.h"
#include "../../engine/graphics/RenderService.h"

class RenderComponent {

  protected:
    int sortLayer = 0;
    int priority = 0;
    unsigned int shaderprogram = 0;

    Mesh* mesh;
    std::vector<float> vertices;


  public:
    RenderComponent();
    RenderComponent(int meshId, unsigned int shaderprogram);
    void render(Entity& entity);
};
