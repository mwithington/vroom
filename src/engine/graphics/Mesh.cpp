#include "Mesh.h"

Mesh::Mesh() {
  this->verts = std::vector<float>();
  this->faces = std::vector<int>();
}

Mesh::Mesh(std::vector<float> verts, std::vector<int> faces) {
  this->verts = verts;
  this->faces = faces;
}
