#include "PlayerRenderComponent.h"
#include <iostream>
#include <ostream>

PlayerRenderComponent::PlayerRenderComponent() {}
PlayerRenderComponent::PlayerRenderComponent(int meshId, unsigned int shaderprogram) {
  RenderComponent(meshId, shaderprogram);
  MeshService::getInstance()->loadMesh("test");
  std::cout << "loaded player mesh" << std::endl;
  this->mesh = MeshService::getInstance()->getMesh(meshId);
  std::cout << "made mesh & loaded" << std::endl;
};
