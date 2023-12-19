#include "MeshService.h"
#include <fstream>
#include <string>

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
  std::cout << "loading meshfile" << std::endl;
  std::ifstream meshFile("./src/player.mesh");
  std::string line;
  std::vector<float> verts;
  std::vector<int> faces;

  bool readingFaces = false;
  if(meshFile.is_open()) {
    std::cout << "open test text"<< line << std::endl;
    if(meshFile.good()){
      while (std::getline(meshFile, line)) {
        std::istringstream iss(line);
        std::string token;
        if(!line.empty()) {
          if (readingFaces) {
            std::cout << "found a face" << std::endl;
            while(std::getline(iss, token, ',')) {
              faces.push_back(std::stoi(token));
            }
          } else {
            std::cout << "found a vert" << std::endl;
            while(std::getline(iss, token, ',')) {
              verts.push_back(std::stof(token));
            }
          }
        } else {
          readingFaces = !readingFaces;
        }
      }
    }
  }


  for (size_t i = 0; i < faces.size(); i++) {
    std::cout << "faces: " << faces[i] << std::endl;
  }
  meshFile.close();
  this->addMesh(Mesh(verts, faces));
}

void MeshService::loadMeshes(std::string file) {}
