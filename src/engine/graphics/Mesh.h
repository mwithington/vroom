#pragma once
#include <vector>
class Mesh {
  public:
    // Ctors
    Mesh();
    Mesh(std::vector<double> verts, std::vector<int> faces);

    // Variables
    std::vector<double> verts;
    std::vector<int> faces;
};
