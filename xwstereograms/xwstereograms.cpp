// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "stdlib.h"
#include "gl/glew.h"
#include <glfw3.h>
#include "render.h"

static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    switch (key)
    {
    case GLFW_KEY_ESCAPE:
        /* Exit program on Escape */
        glfwSetWindowShouldClose(window, GLFW_TRUE);
        break;
    }
}


static void error_callback(int error, const char* description)
{
    fprintf(stderr, "Error: %s\n", description);
}

int _tmain(int argc, _TCHAR* argv[])
{

    GLFWwindow* window;
    int iter;
    double dt;
    //double last_update_time;
    int frame;
    //float f;
    GLint uloc_modelview;
    GLint uloc_project;
    int width, height;

    GLuint shader_program;

    glfwSetErrorCallback(error_callback);

    if (!glfwInit())
        exit(EXIT_FAILURE);

    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GLFW_TRUE);

    window = glfwCreateWindow(800, 600, "xw stereograms", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        exit(EXIT_FAILURE);
    }

    /* Register events callback */
    glfwSetKeyCallback(window, key_callback);

    glfwMakeContextCurrent(window);

    initRender();

    while (!glfwWindowShouldClose(window))
    {

        /* render the next frame */
        glClear(GL_COLOR_BUFFER_BIT);

        render();
        /* display and process events through callbacks */
        glfwSwapBuffers(window);
        glfwPollEvents();
        /* Check the frame rate and update the heightmap if needed */
        //dt = glfwGetTime();
        //if ((dt - last_update_time) > 0.2)
        //{

        //}
    }

    glfwTerminate();
    exit(EXIT_SUCCESS);
	return 0;
}

