#include <GLFW/glfw3.h>
#include <stdlib.h>
#include <stdio.h>
#include <Windows.h>

#pragma comment(lib,"OpenGL32")

static void error_callback(int error, const char* description)
{
    fputs(description, stderr);
}
static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GL_TRUE);
}
int main(void)
{
    GLFWwindow* window;
    float yPoint = 0.07f;
    float yPoint2 = 0.0;;
    float xPoint = 0.8f;
    float xPoint2 = 0.6f;

    glfwSetErrorCallback(error_callback);
    if (!glfwInit())
        exit(EXIT_FAILURE);
    window = glfwCreateWindow(640, 480, "Simple example", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        exit(EXIT_FAILURE);
    }
    glfwMakeContextCurrent(window); //gpu정리
    glfwSetKeyCallback(window, key_callback);
    
    float ratio;
    int width, height;
    glfwGetFramebufferSize(window, &width, &height); //framebuffer = 화면에 담겨질 메모리 공간?
    ratio = width / (float)height;

    while (!glfwWindowShouldClose(window))
    {
        glClearColor(1.0f, 1.0f, 1.0f, 1.0f); // 화면을 한가지 색으로 채운다(클리어하겠다)
        glClear(GL_COLOR_BUFFER_BIT);

        if (GetAsyncKeyState(VK_SPACE) & 0x8000 || GetAsyncKeyState(VK_SPACE) & 0x8001)
        {
            yPoint = 0.27f;
            yPoint2 = 0.20f;
        }
        else
        {
            yPoint = 0.07f;
            yPoint2 = 0.0f;
        }

        glPointSize(5);
        glBegin(GL_TRIANGLES);

        glColor3f(0.0f, 0.0f, 1.0f);
        glVertex2f(-0.07f, yPoint);
        glColor3f(0.0f, 1.0f, 0.0f);
        glVertex2f(-0.07f, yPoint2);
        glColor3f(1.0f, 0.0f, 0.0f);
        glVertex2f(0.0f, yPoint2);

        glEnd();

        glPointSize(5);
        glBegin(GL_TRIANGLES);

        glColor3f(0.0f, 0.0f, 1.0f);
        glVertex2f(-0.07f, yPoint);
        glColor3f(0.0f, 1.0f, 0.0f);
        glVertex2f(0.0f, yPoint);
        glColor3f(1.0f, 0.0f, 0.0f);
        glVertex2f(0.0f, yPoint2);

        glEnd();

        glPointSize(5);
        glBegin(GL_TRIANGLES);

        glColor3f(0.0f, 1.0f, 1.0f);
        glVertex2f(xPoint2, 0.0f);
        glColor3f(0.0f, 1.0f, 1.0f);
        glVertex2f(xPoint, 0.0f);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex2f(xPoint, 0.15f);

        glEnd();

        if (xPoint < -1.0f)
            xPoint = 0.8f;
        else
            xPoint = xPoint - 0.003f;
        if (xPoint2 < -1.2f)
            xPoint2 = 0.6f;
        else
            xPoint2 = xPoint2 - 0.003f;
        
       

        glfwSwapBuffers(window);
        glfwPollEvents(); // 이벤트를 계속 체크
    }
    glfwDestroyWindow(window);
    glfwTerminate();
    exit(EXIT_SUCCESS);
}