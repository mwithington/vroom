#include "PlayerRenderComponent.h"
#include <iostream>
#include <ostream>

PlayerRenderComponent::PlayerRenderComponent() {}
PlayerRenderComponent::PlayerRenderComponent(int meshId) {
  MeshService::getInstance()->loadMesh("test");
  std::cout << "loaded player mesh" << std::endl;
  this->mesh = MeshService::getInstance()->getMesh(meshId);
  std::cout << "made mesh & loaded" << std::endl;
  this->vertices = std::vector<float>();
};

void PlayerRenderComponent::render(Player& player, unsigned int shaderprogram){
  this->vertices.clear();
  const int WIDTH = 900, HEIGHT = 600;
  const int gridWidth = (WIDTH / 2.0), gridHeight = (HEIGHT / 2.0);
  const double scaledPlayerX = (player.pos.x - gridWidth) / gridWidth;
  const double scaledPlayerY = (player.pos.y - gridHeight) / gridHeight;

  const double x1 = scaledPlayerX + (mesh->verts[0]/WIDTH);
  const double y1 = scaledPlayerY + (mesh->verts[1]/HEIGHT);
  const double x2 = scaledPlayerX + (mesh->verts[3]/WIDTH);
  const double y2 = scaledPlayerY + (mesh->verts[4]/HEIGHT);
  const double x3 = scaledPlayerX + (mesh->verts[6]/WIDTH);
  const double y3 = scaledPlayerY + (mesh->verts[7]/HEIGHT);
  const double x4 = scaledPlayerX + (mesh->verts[9]/WIDTH);
  const double y4 = scaledPlayerY + (mesh->verts[10]/HEIGHT);

  this->vertices.push_back(x1);
  this->vertices.push_back(y1);
  this->vertices.push_back(0.0f);

  this->vertices.push_back(x2);
  this->vertices.push_back(y2);
  this->vertices.push_back(0.0f);

  this->vertices.push_back(x3);
  this->vertices.push_back(y3);
  this->vertices.push_back(0.0f);

  this->vertices.push_back(x4);
  this->vertices.push_back(y4);
  this->vertices.push_back(0.0f);

  std::cout << "scaled: " << x1 << ", " << y1 << std::endl;

  RenderService::getInstance()->renderMesh(vertices, mesh->faces, shaderprogram);

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
