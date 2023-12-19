#pragma once
#include <vector>
class Mesh {
  public:
    // Ctors
    Mesh();
    Mesh(std::vector<float> verts, std::vector<int> faces);

    // Variables
    std::vector<float> verts;
    std::vector<int> faces;
};
