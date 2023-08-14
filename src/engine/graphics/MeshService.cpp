#include "MeshService.h"
#include <fstream>
#include <sstream>
#include <string>
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

void MeshService::loadMesh(std::string file) {
  std::ifstream meshFile("../../player.mesh");
  std::string line;
  std::vector<float> verts;
  std::vector<int> faces;

  bool readingFaces = false;

  while (std::getline(meshFile, line)) {
    if(!line.empty()) {
      if (readingFaces) {
        faces.push_back(1);
      } else {

        verts.push_back(1);
      }
    } else {
      readingFaces = !readingFaces;
    }

  }

  meshFile.close();
}

void MeshService::loadMeshes(std::string file) {}
