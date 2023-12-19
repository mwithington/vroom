#include "RenderService.h"
#include <iostream>

RenderService* RenderService::instance = nullptr;

RenderService::RenderService() {}

RenderService* RenderService::getInstance() {
  if(instance == nullptr){
    instance = new RenderService();
  }

  return instance;
}

void RenderService::renderMesh(Mesh* mesh, int scale) {

};

void RenderService::renderMesh(std::vector<float> verts, std::vector<int> faces, unsigned int shaderProgram) {
  unsigned int VBO, VAO, EBO;

  glUseProgram(shaderProgram);
  glGenVertexArrays(1, &VAO);
  glGenBuffers(1, &VBO);
  glGenBuffers(1, &EBO);
  // bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s).
  glBindVertexArray(VAO);

  glBindBuffer(GL_ARRAY_BUFFER, VBO);
  glBufferData(GL_ARRAY_BUFFER, sizeof(float) * verts.size(), &verts[0], GL_STATIC_DRAW);

  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(int) * faces.size(), &faces[0], GL_STATIC_DRAW);

  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
  glEnableVertexAttribArray(0);

  // note that this is allowed, the call to glVertexAttribPointer registered VBO as the vertex attribute's bound vertex buffer object so afterwards we can safely unbind
  glBindBuffer(GL_ARRAY_BUFFER, 0);
  glDrawElements(GL_TRIANGLES, faces.size(), GL_UNSIGNED_INT, 0);
};

void RenderService::renderMesh(std::vector<float> verts, std::vector<int> faces, int scale) {

};
