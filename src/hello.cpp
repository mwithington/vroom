#include <iostream>
#include <string>
#include <vector>

// GLAD
#define GLAD_GL_IMPLEMENTATION
#include <glad/gl.h>

// GLFW
#include <GLFW/glfw3.h>
// #include <GLFW/aglfw3.h>

#include "./game/tile/tile.h"
#include "./game/player/player.h"
#include "./engine/config/ConfigService.h"
#include "./game/world/board/Board.h"
#include "engine/entity/entity.h"

// This example is taken from http://learnopengl.com/
// http://learnopengl.com/code_viewer.php?code=getting-started/hellowindow2
// The code originally used GLEW, I replaced it with Glad

// Declarations
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode);

void handleInput();
void update(std::vector<Entity*> entityList);
// void render(GLFWwindow* window, Camera* cam, std::vector<Entity*> entityList);
void render(GLFWwindow* window);

int main()
{
    // Init GLFW
    glfwInit();
    // Set all the required options for GLFW
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

    // Init ConfigService
    ConfigService configSvc = ConfigService();
    std::cout << "Loading config..." << std::endl;
    configSvc.loadConfig("./config.tcd");
    std::cout << "Loaded config..." << std::endl;

    // Create window
    const int WIDTH = configSvc.getIntValue("WINDOW_WIDTH", 600), HEIGHT = configSvc.getIntValue("WINDOW_HEIGHT", 800);
    std::cout << "Config: " << "WINDOW_HEIGHT: " << HEIGHT << std::endl;
    std::cout << "Config: " << "WINDOW_WIDTH: " << WIDTH << std::endl;

    const std::string TITLE = configSvc.getValue("WINDOW_TITLE", "So far so good");

    GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, &(TITLE[0]), NULL, NULL);
    glfwMakeContextCurrent(window);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }

    // Set the required callback functions
    glfwSetKeyCallback(window, key_callback);

#ifdef GLAD_OPTION_GL_MX
    GladGLContext context = {};
  #ifdef GLAD_OPTION_GL_LOADER
    int version = gladLoaderLoadGLContext(&context);
  #else
    int version = gladLoadGLContext(&context, glfwGetProcAddress);
  #endif
#else
  #ifdef GLAD_OPTION_GL_LOADER
    int version = gladLoaderLoadGL();
  #else
    int version = gladLoadGL(glfwGetProcAddress);
  #endif
#endif

    if (version == 0)
    {
        std::cout << "Failed to initialize OpenGL context" << std::endl;
        return -1;
    }

    std::cout << "Loaded OpenGL " << GLAD_VERSION_MAJOR(version) << "." << GLAD_VERSION_MINOR(version) << std::endl;

    // Define the viewport dimensions
    glViewport(0, 0, WIDTH, HEIGHT);

    Tile t = Tile();
    Player p = Player();
    Board b = Board(13, 11);

    b.getTiles()[3][3].setType(5);

    std::cout << "Tile: " << "x: " << t.pos.x << ", y: " << t.pos.y << std::endl;
    std::cout << "Player: " << "x: " << p.pos.x << ", y: " << p.pos.y << std::endl;
    b.render();

    // Game loop
    while (!glfwWindowShouldClose(window))
    {
      handleInput();

      // update();

      render(window);
    }

    // Terminates GLFW, clearing any resources allocated by GLFW.
    glfwTerminate();
    return 0;
}

// Is called whenever a key is pressed/released via GLFW
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GL_TRUE);
}

void handleInput() {
  // Check if any events have been activated (key pressed, mouse moved etc.) and call corresponding response functions
  glfwPollEvents();


}

void update(std::vector<Entity*> entityList) {
  for (int i = 0; i < entityList.size(); i++) {
    entityList[i]->update();
  }
}

void render(GLFWwindow* window) {
  // TODO(Tom): have some global counter and only render if it's been >1/60th of a second since last frame


  // Clear the colorbuffer
  glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
  glClear(GL_COLOR_BUFFER_BIT);

  // Render world entities

  // Swap the screen buffers
  glfwSwapBuffers(window);
}
