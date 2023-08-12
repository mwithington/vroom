#import "Mesh.h"

Mesh::Mesh() {
  this->verts = std::vector<double>();
  this->faces = std::vector<int>();
}

Mesh::Mesh(std::vector<double> verts, std::vector<int> faces) {
  this->verts = verts;
  this->faces = faces;
}
