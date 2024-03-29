#include <cstdint>
#include <iostream>
#include <ostream>
#include <stdint.h>
#include <string>
#include <time.h>
#include <tuple>
#include <vector>
#include <ctime>
#include <chrono>
#include <thread>
// #define CLOCKS_PER_SEC 100000

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
#include "engine/input/Keyboard.h"

const char *vertexShaderSource = "#version 330 core\n"
    "layout (location = 0) in vec3 aPos;\n"
    "void main()\n"
    "{\n"
    "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
    "}\0";
const char *fragmentShaderSource = "#version 330 core\n"
    "out vec4 FragColor;\n"
    "void main()\n"
    "{\n"
    "   FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
    "}\n\0";

// This example is taken from http://learnopengl.com/
// http://learnopengl.com/code_viewer.php?code=getting-started/hellowindow2
// The code originally used GLEW, I replaced it with Glad

// Declarations
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode);
void glfwErrorCallback(int error, const char* description);

void handleInput();
void update(std::vector<Entity*> entityList, double gameTimeElapsed);
// void render(GLFWwindow* window, Camera* cam, std::vector<Entity*> entityList);
void render(GLFWwindow* window, unsigned int shaderProgram, unsigned int VAO);

int main()
{
    uint32_t start = std::clock();
    // Init GLFW
    glfwInit();
    glfwSetErrorCallback(glfwErrorCallback);
    // Set all the required options for GLFW
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GLFW_TRUE);

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

    Keyboard* keyboard = Keyboard::getInstance();

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

    std::cout << "creating player" << std::endl;
    Player p = Player();
    p.init();
    Board b = Board(13, 11);

    b.getTiles()[3][3].setType(5);

    std::cout << "Tile: " << "x: " << t.pos.x << ", y: " << t.pos.y << std::endl;
    std::cout << "Player: " << "x: " << p.pos.x << ", y: " << p.pos.y << std::endl;
    b.render();

    auto entityList = std::vector<Entity*>();
    entityList.push_back(&p);

    uint32_t micros = (std::clock() - start) / (double)(CLOCKS_PER_SEC);
    std::cout << "time: " << micros << std::endl;

    // Game loop
    // uint32_t lastTime = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
    uint32_t lastTime = (float)glfwGetTime();
    uint32_t currentTime = 0;
    double gameTimeElapsed = 0;
    std::this_thread::sleep_for(std::chrono::milliseconds(10));
    std::cout << "clock: " << std::clock() << std::endl;
    std::cout << "clocks per sec: " << CLOCKS_PER_SEC << std::endl;
    std::cout << "glfw time: " << (float)glfwGetTime() << std::endl;

        // vertex shader
    unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    glCompileShader(vertexShader);
    // check for shader compile errors
    int success;
    char infoLog[512];
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
    }
    // fragment shader
    unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
    glCompileShader(fragmentShader);
    // check for shader compile errors
    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
    }
    // link shaders
    unsigned int shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);
    // check for linking errors
    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
    if (!success) {
        glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
    }
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);

    float vertices[] = {
         0.5f,  0.5f, 0.0f,  // top right
         0.5f, -0.5f, 0.0f,  // bottom right
        -0.5f, -0.5f, 0.0f,  // bottom left
        -0.5f,  0.5f, 0.0f   // top left
    };
    unsigned int indices[] = {  // note that we start from 0!
        0, 1, 3,  // first Triangle
        1, 2, 3   // second Triangle
    };
    unsigned int VBO, VAO, EBO;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);
    // bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s).
    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    // note that this is allowed, the call to glVertexAttribPointer registered VBO as the vertex attribute's bound vertex buffer object so afterwards we can safely unbind
    glBindBuffer(GL_ARRAY_BUFFER, 0);

    // remember: do NOT unbind the EBO while a VAO is active as the bound element buffer object IS stored in the VAO; keep the EBO bound.
    //glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

    // You can unbind the VAO afterwards so other VAO calls won't accidentally modify this VAO, but this rarely happens. Modifying other
    // VAOs requires a call to glBindVertexArray anyways so we generally don't unbind VAOs (nor VBOs) when it's not directly necessary.
    glBindVertexArray(0);

    vertices[0] -= 0.00001f;

    while (!glfwWindowShouldClose(window))
    {
      // currentTime = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
      currentTime = (float)glfwGetTime() * 1000;
      gameTimeElapsed = (currentTime - lastTime);

      // std::cout << "itz tiiiime: " << currTimeMsEpoch << std::endl;
      handleInput();

      update(entityList, gameTimeElapsed);

      // TODO(Tom): create timer loop to limit redraws (maybe a config flag for uncapped fps)
      render(window, shaderProgram, VAO);
      lastTime = currentTime;

      std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }

    // Terminates GLFW, clearing any resources allocated by GLFW.
    glfwTerminate();
    return 0;
}


// Is called whenever a key is pressed/released via GLFW
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode)
{
  Keyboard* keyboard = Keyboard::getInstance();
  if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
    std::cout << "Key pressed: " << keyboard->isKeyDown(GLFW_KEY_E) << std::endl;
    glfwSetWindowShouldClose(window, GL_TRUE);
  }

  if(key >= 0) {
    // std::cout << "Key pressed: " << key << " is down: >" << keyboard->isKeyDown(key) << std::endl;
    keyboard->setKey(key, action);
  }
}


void handleInput() {
  // Check if any events have been activated (key pressed, mouse moved etc.) and call corresponding response functions
  glfwPollEvents();
}

void update(std::vector<Entity*> entityList, double gameTimeElapsed) {
  for (int i = 0; i < entityList.size(); i++) {
     entityList[i]->update(gameTimeElapsed);
  }
}

void render(GLFWwindow* window, unsigned int shaderProgram, unsigned int VAO) {
  // TODO(Tom): have some global counter and only render if it's been >1/60th of a second since last frame


  // Clear the colorbuffer
  glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
  glClear(GL_COLOR_BUFFER_BIT);

  // Render world entities
  glUseProgram(shaderProgram);
  glBindVertexArray(VAO); // seeing as we only have a single VAO there's no need to bind it every time, but we'll do so to keep things a bit more organized
                          //glDrawArrays(GL_TRIANGLES, 0, 6);
  glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

  // Swap the screen buffers
  glfwSwapBuffers(window);
}


void glfwErrorCallback(int error, const char* description) {
  std::cout << "GLFW Error: " << error << " - " << description << std::endl;
}
