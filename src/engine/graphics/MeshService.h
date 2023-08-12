#pragma once

#include "Mesh.h"
#include <vector>

class MeshService {
  private:
    // Variables
    std::vector<Mesh> meshes;
    static MeshService* instance;

    // Ctors
    MeshService();

  public:
    // Methods
    static MeshService* getInstance();
    Mesh* getMesh(int id);
    void addMesh(Mesh mesh);
    void addMeshs(std::vector<Mesh>);
};
