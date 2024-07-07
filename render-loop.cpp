#include <GLFW/glfw3.h>
#include <iostream>
#include <stdlib.h>

using namespace std;

void error_callback(int error, const char *description) {
  fprintf(stderr, "Error: %s\n", description);
}

static void key_callback(GLFWwindow *window, int key, int scancode, int action,
                         int mods) {
  if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
    glfwSetWindowShouldClose(window, GLFW_TRUE);
}

GLFWwindow *window_init() {
  GLFWwindow *window = nullptr;
  if (glfwInit() == GLFW_TRUE) {
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwSetErrorCallback(error_callback);
    window = glfwCreateWindow(640, 480, "Hello Game World!", NULL, NULL);
    glfwMakeContextCurrent(window);
    cout << "OpenGL Vendor: " << glGetString(GL_VENDOR) << endl;
    cout << "OpenGL Renderer: " << glGetString(GL_RENDERER) << endl;
    cout << "OpenGL Version: " << glGetString(GL_VERSION) << endl;
  }

  if (window == nullptr) {
    cout << "window creation failed" << endl;
    exit(EXIT_FAILURE);
  }

  return window;
}

void window_destroy(GLFWwindow *window) {
  glfwDestroyWindow(window);
  glfwTerminate();
}

void game_loop(GLFWwindow *window) {
  int width;
  int height;
  while (!glfwWindowShouldClose(window)) {
    glfwGetFramebufferSize(window, &width, &height);
    // glViewport(0, 0, width, height);
    // glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glfwSwapBuffers(window);
    glfwPollEvents();
  }
};

int main() {
  GLFWwindow *window = window_init();
  game_loop(window);
  window_destroy(window);
}
