#include <GLES2/gl2.h>
#include <stdio.h>

#include "glad/glad.h"
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

    float vertices[] = {
        -0.5f, -0.5f, 0.0f,
        0.5f, -0.5f, 0.0f,
        -0.5f, 0.5f, 0.0f
    };

    unsigned int vbo_id;
    // generates buffer in GPU
    glGenBuffers(1, &vbo_id);
    // binds buffer to an array buffer
    glBindBuffer(GL_ARRAY_BUFFER, vbo_id);
    // copy data into buffer
    // Last arg has a few possible options
    // GL_STATIC_DRAW: data is set only once and used by the GPU at most a few times
    // GL_STREAM_DRAW: data is set only once and used many times
    // GL_DYNAMIC_DRAW: changed a lot and used many times
    // in our case, we set it once and aren't dynamically changing these veritces
    glBufferData(GL_ARRAY_BUFFER, sizeof vertices, vertices, GL_STATIC_DRAW);

    const char *vertex_shader = "#version 330 core\n"
        "layout (location = 0) in vec3 pos;\n"
        "void main() {\n"
        "gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
        "}\0";
    unsigned int vertex_shader_id = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertex_shader_id, 1, &vertex_shader, NULL);
    glCompileShader(vertex_shader_id);

    while(!glfwWindowShouldClose(window)) {
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glDeleteShader(vertex_shader_id);
    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}
