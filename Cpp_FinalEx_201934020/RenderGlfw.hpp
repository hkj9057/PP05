#include <GLFW/glfw3.h> 
#include <stdlib.h>
#include <stdio.h>
#include <Windows.h>
#include <iostream>

#pragma comment(lib,"OpenGL32") 

namespace JunSeok_Game
{
    class RenderGlfw
    {
    public:

        GLFWwindow* window;
        

        static void error_callback(int error, const char* description)
        {
            fputs(description, stderr);
        }
        static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
        {
            if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
                glfwSetWindowShouldClose(window, GL_TRUE);
        }
        void GlfwStart()
        {
            glfwSetErrorCallback(error_callback);
            if (!glfwInit())
                exit(EXIT_FAILURE);
            window = glfwCreateWindow(640, 480, "Simple example", NULL, NULL);
            if (!window)
            {
                glfwTerminate();
                exit(EXIT_FAILURE);
            }
            glfwMakeContextCurrent(window);
            glfwSetKeyCallback(window, key_callback);

            float ratio;
            int width, height;
            glfwGetFramebufferSize(window, &width, &height);
            ratio = width / (float)height;
        }
        void EndGlfw()
        {
            glfwDestroyWindow(window);
            glfwTerminate();
            exit(EXIT_SUCCESS);
        }

        void Draw(float x, float y, float color)
        {
            glEnable(GL_BLEND);
            glBlendFunc(GL_SRC_ALPHA, GL_ONE);

           // glClearColor(1.0f, 1.0f, 0.0f, 1.0f);
            glClear(GL_COLOR_BUFFER_BIT);

            glPointSize(20);
            glBegin(GL_POINTS); // 점(플레이어)
           // glColor4f(1.0f, 0.0f, 0.0f, 1.0f);
            glColor3f(1.0f, color, 0.0f);
            glVertex2f(x, y);
            
        
        }
        void SwapBuffer()
        
        {
            glEnd();
            glfwSwapBuffers(window); 
            glfwPollEvents(); 
        }
    };
}