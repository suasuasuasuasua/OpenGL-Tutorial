#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

constexpr unsigned int WIDTH = 800, HEIGHT = 600;

void processInput(GLFWwindow* window);
void framebuffer_size_callback(GLFWwindow* window, int width, int height);

int main()
{
    /**
     * Initialize the GLFW window.
     * Here we set the required version of GLFW to 3.3.
     * Finally, we choose the core-profile for access to only a subset of essential features.
     */
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#if __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

    /**
     * Next, we need to create the window object to hold the windowing information.
     * This object is required by most of the other GLFW functions
     */
    GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "Chapter 4: Hello Window", NULL, NULL);
    if (window == NULL) {
        std::cout << "Failed to create a GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);

    /**
     * Initialize GLAD to handle GLFW function pointers
     */
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    /**
     * The last thing to do is tell OpenGL the size of the rendering window
     * so that OpenGL knows how we want to display the data and coordinates with respect to the window.
     *
     * The first two parameters set the location of the lower left corner of the window; the last two
     * parameters set the width and height of the window in pixels.
     */
    glViewport(0, 0, WIDTH, HEIGHT);

    /**
     * Whenever the window is resized, we want to re-register the window size for rendering.
     * This is because the window and viewport should be resized at the same time.
     */
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    /**
     * Create a simple render loop.
     *
     * Each iteration of this loop is called a frame.
     */
    while (!glfwWindowShouldClose(window)) {
        // Input
        processInput(window);

        // Rendering commands here
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f); // Set the color of the clear function
        glClear(GL_COLOR_BUFFER_BIT); // Clear the screen from the previous buffer

        // Check and call events and swap the buffers
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    /**
     * Gracefully terminate and delete all of GLFW's resources that were allocated
     */
    glfwTerminate();

    return 0;
}

/**
 * Define a callback function tha resizes the viewport if the window size changes
 */
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}

/**
 * Define a function that processes input from the user each iteration of the loop.
 *
 * Here, if the user presses the escape key, then the window should close
 */
void processInput(GLFWwindow* window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
        glfwSetWindowShouldClose(window, true);
    }
}
