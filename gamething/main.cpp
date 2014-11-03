//
//  main.cpp
//  gamething
//
//  Created by Marko Heini on 03/11/14.
//  Copyright (c) 2014 mh. All rights reserved.
//

#include <iostream>

#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#define FPS 1.0/60

static void error_callback(int error, const char* description)
{
    fputs(description, stderr);
}

static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
        glfwSetWindowShouldClose(window, GL_TRUE);
    }
}

int main(int argc, const char * argv[])
{

    GLFWwindow* pWindow;
    glfwSetErrorCallback(error_callback);

    if (!glfwInit()) {
        exit(EXIT_FAILURE);
    }

    glfwWindowHint(GLFW_SAMPLES, 4);

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    pWindow = glfwCreateWindow(640, 480, "window", NULL, NULL);
    if (!pWindow) {
        glfwTerminate();
        exit(EXIT_FAILURE);
    }

    glfwMakeContextCurrent(pWindow);
    glewExperimental = GL_TRUE;

    // Initialize GLEW
    GLenum rc = glewInit();
    if (rc != GLEW_OK) {
        fprintf(stderr, "GLEW error: '%s'\n", glewGetErrorString(rc));
        exit(EXIT_FAILURE);
    }

    // Ensure we can capture the escape key
    glfwSetInputMode(pWindow, GLFW_STICKY_KEYS, GL_TRUE);

    // Enable depth test
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);

    glfwSetKeyCallback(pWindow, key_callback);

    const GLubyte* renderer = glGetString (GL_RENDERER); // get renderer string
    const GLubyte* version = glGetString (GL_VERSION); // version as a string

    std::cout << "Renderer: " << renderer << "\n";
    std::cout << "OpenGL version supported: " << version << "\n";
    std::cout << "Shader lang: " << glGetString(GL_SHADING_LANGUAGE_VERSION) << "\n";

    double currentTimeMillis = 0;
    double lastRenderMillis = 0;

    bool running = true;
    while (running == 1) {

        currentTimeMillis = glfwGetTime();

        glfwPollEvents();

        // update();

        if(currentTimeMillis - lastRenderMillis > FPS) {
            // render(pWindow);
            lastRenderMillis = glfwGetTime();
        }

        if(glfwGetKey(pWindow, GLFW_KEY_ESCAPE ) == GLFW_PRESS ||
                glfwWindowShouldClose(pWindow) == 1) {
            // Break the loop
            running = false;
        }
    }

    return 0;
}
