
#include <GLFW/glfw3.h>

#include <Windows.h>

#include <iostream>

#include "GameManager.h"

//void renderGameObject(const GameObject* go)
//{
    //std::pair<int, int> goPosition = std::make_pair(go->position.first, go->position.second);
    //std::pair<int, int> goSize = std::make_pair(go->size.first, go->size.second);

    //float glCoordX = go->position.first / 100.0f, glCoordY = go->position.second / 100.0f;
    //float glSizeW = go->size.first / 100.0f, glSizeH = go->size.second / 100.0f;

    //glfwGetWindowSize()

    //glBegin(GL_POLYGON);
    //glVertex2f()
//}

void setupWindowTest()
{

}

int main(void)
{
    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);

    //CONSOLE_SCREEN_BUFFER_INFO csbi;
    //int windowWidth, windowHeight;

    //GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    //windowWidth = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    //windowHeight = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;

    //std::cout << "Window width: " << windowWidth << ", height: " << windowHeight << '\n';

    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        glBegin(GL_POLYGON);
        //glVertex2f(-0.5f, -0.5f);
        //glVertex2f(0.0f, 0.5f);
        //glVertex2f(0.5f, -0.5f);
        glVertex2f(-0.5f, 0.5f);
        glVertex2f(0.5f, 0.5f);
        glVertex2f(0.5f, -0.5f);
        glVertex2f(-0.5f, -0.5f);
        //glVertex2f(0.0f, -0.5f);
        glEnd();

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}