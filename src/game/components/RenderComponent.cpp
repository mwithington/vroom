#include "RenderComponent.h"
#include <iostream>
#include <ostream>

RenderComponent::RenderComponent() {}
RenderComponent::RenderComponent(int meshId, std::string meshFile, unsigned int shaderprogram) {
  MeshService::getInstance()->loadMesh(meshFile);
  std::cout << "loaded entity mesh" << std::endl;
  this->mesh = MeshService::getInstance()->getMesh(meshId);
  std::cout << "made mesh & loaded" << std::endl;

  std::cout << "setting shaderprogram: " << shaderprogram << std::endl;
  this->shaderprogram = shaderprogram;
  std::cout << "set shaderprogram: " << this->shaderprogram << std::endl;

  this->vertices = std::vector<float>();
};

void RenderComponent::render(Entity& entity){
  std::cout << "Rendering mesh...clearing" << std::endl;
  this->vertices.clear();
  std::cout << "Rendering mesh...calcs" << std::endl;
  const int WIDTH = 900, HEIGHT = 600;
  const int gridWidth = (WIDTH / 2.0), gridHeight = (HEIGHT / 2.0);
  const double scaledEntityX = (entity.pos.x - gridWidth) / gridWidth;
  const double scaledEntityY = (entity.pos.y - gridHeight) / gridHeight;

  // std::cout << "mesh verts: " << mesh->verts.size() << std::endl;
  std::cout << "Rendering mesh...verts" << std::endl;
  for (int i = 0; i < mesh->verts.size(); i += 3) {
    std::cout << "building scaled verts: " << i << " of " << mesh->verts.size() << std::endl;
    this->vertices.push_back(scaledEntityX + (mesh->verts[i]/WIDTH));
    this->vertices.push_back(scaledEntityY + (mesh->verts[i + 1]/HEIGHT));
    this->vertices.push_back(0.0f);
  }

  // Call glUseProgram() with a shader program maybe
  std::cout << "Rendering mesh..." << std::endl;
  RenderService::getInstance()->renderMesh(vertices, mesh->faces, this->shaderprogram);

  /*
   * TODO(MIKE): Remove this
  unsigned int VBO, VAO, EBO;
  glGenVertexArrays(1, &VAO);
  glGenBuffers(1, &VBO);
  glGenBuffers(1, &EBO);
  // bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s).
  glBindVertexArray(VAO);

  glBindBuffer(GL_ARRAY_BUFFER, VBO);
  glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(mesh->faces), mesh->faces, GL_STATIC_DRAW);

  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
  glEnableVertexAttribArray(0);

  // note that this is allowed, the call to glVertexAttribPointer registered VBO as the vertex attribute's bound vertex buffer object so afterwards we can safely unbind
  glBindBuffer(GL_ARRAY_BUFFER, 0);
  */
};
