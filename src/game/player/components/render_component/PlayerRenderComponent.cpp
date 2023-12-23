#include "PlayerRenderComponent.h"
#include <iostream>
#include <ostream>

PlayerRenderComponent::PlayerRenderComponent() {}
PlayerRenderComponent::PlayerRenderComponent(int meshId, unsigned int shaderprogram) {
  std::cout << "setting shaderprogram: " << shaderprogram << std::endl;
  this->shaderprogram = shaderprogram;
  MeshService::getInstance()->loadMesh("./src/meshes/player.mesh");
  std::cout << "loaded player mesh" << std::endl;
  this->mesh = MeshService::getInstance()->getMesh(meshId);
  std::cout << "made mesh & loaded" << std::endl;
};
