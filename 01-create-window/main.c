#include <GL/gl.h>
#include <stdio.h>

#include "GLFW/glfw3.h"

void log_error(char *message) {
    printf("[ERROR] - %s", message);
}

int main() {
    if (!glfwInit()) {
        log_error("glfw was not initialized");
    }
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glViewport(0, 0, 800, 600);

    GLFWwindow * window = glfwCreateWindow(800, 600, "Hello World!", NULL, NULL);
    if (!window) {
        log_error("Window no work");
        glfwTerminate();
        return -1;
    }

    while(!glfwWindowShouldClose(window)) {
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}
