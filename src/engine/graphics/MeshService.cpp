#include "MeshService.h"
#include <vector>

MeshService* MeshService::instance = nullptr;

MeshService::MeshService() {
  this->meshes = std::vector<Mesh>();
}

MeshService* MeshService::getInstance() {
  if(instance == nullptr){
    instance = new MeshService();
  }

  return instance;
}

Mesh* MeshService::getMesh(int id) {
  return &meshes.at(id);
}

void MeshService::addMesh(Mesh mesh){
  meshes.push_back(mesh);
}

void MeshService::addMeshs(std::vector<Mesh> additionalMeshes) {
  for (int i = 0; i < additionalMeshes.size(); i++) {
    Mesh mesh = meshes.at(i);
    this->meshes.push_back(mesh);
  }
}
