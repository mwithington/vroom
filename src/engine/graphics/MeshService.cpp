#include "MeshService.h"

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
  std::cout << "size: " << meshes.size() << std::endl;
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
    std::istringstream iss(line);
    std::string token;
    if(!line.empty()) {
      if (readingFaces) {
        while(std::getline(iss, token, ',')) {
          faces.push_back(std::stoi(token));
        }
      } else {
        while(std::getline(iss, token, ',')) {
          verts.push_back(std::stof(token));
        }
      }
    } else {
      readingFaces = !readingFaces;
    }
  }
  meshFile.close();
  this->addMesh(Mesh(verts, faces));
}

void MeshService::loadMeshes(std::string file) {}
