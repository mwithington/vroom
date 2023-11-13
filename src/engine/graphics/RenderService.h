#pragma once

#include "Mesh.h"
#include <vector>
#include <glad/gl.h>

class RenderService {
  private:
    // Variables
    static RenderService* instance;

    // Ctors
    RenderService();

  public:
    // Methods
    static RenderService* getInstance();

    void renderMesh(Mesh* mesh, int scale);
    void renderMesh(std::vector<float> verts, std::vector<int> faces);
    void renderMesh(std::vector<float> verts, std::vector<int> faces, int scale);
};
