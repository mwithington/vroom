#pragma once

#include "Mesh.h"
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

class MeshService {
  private:
    // Variables
    std::vector<Mesh*> meshes;
    static MeshService* instance;

    // Ctors
    MeshService();

  public:
    // Methods
    static MeshService* getInstance();
    Mesh* getMesh(int id);

    void addMesh(Mesh* mesh);
    void addMeshs(std::vector<Mesh*>);

    void loadMeshes(std::string file);
    void loadMesh(std::string file);
};
