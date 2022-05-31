#include <GLFW/glfw3.h> //그래픽 라이브러리 프레임워크
#include <stdlib.h>
#include <stdio.h>
#include <Windows.h>
#include <iostream>

#pragma comment(lib,"OpenGL32") // 

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
            window = glfwCreateWindow(640, 480, "Simple example", NULL, NULL);// 윈도우창 생성
            if (!window)
            {
                glfwTerminate();
                exit(EXIT_FAILURE);
            }
            glfwMakeContextCurrent(window); //Context를 장악, gpu정리 , conext = 클래스묶음?    s = 스레드 = 동시에 여러개를 돌린다
            glfwSetKeyCallback(window, key_callback);

            float ratio;
            int width, height;
            glfwGetFramebufferSize(window, &width, &height); //framebuffer = 화면에 담겨질 메모리 공간?
            ratio = width / (float)height;
        }
        void EndGlfw()
        {
            glfwDestroyWindow(window);
            glfwTerminate();
            exit(EXIT_SUCCESS);
        }

        void Draw(float x, float y)
        {
            glEnable(GL_BLEND);
            glBlendFunc(GL_SRC_ALPHA, GL_ONE);

            glClearColor(1.0f, 1.0f, 0.0f, 1.0f); // 화면을 한가지 색으로 채운다(클리어하겠다)
            glClear(GL_COLOR_BUFFER_BIT);

            glPointSize(20);
            glBegin(GL_POINTS); // 점(플레이어)

            glColor4f(1.0f, 0.0f, 0.0f, 1.0f);
            glVertex2f(x, y);
            //glColor4f(1.0f, 0.0f, 0.0f, 1.0f);
            //glVertex2f(x1, y2);
            //glColor4f(1.0f, 0.0f, 0.0f, 1.0f);
            //glVertex2f(x2, y2);

            glEnd();

            //glPointSize(10);
            //glBegin(GL_TRIANGLES);

            //glColor4f(1.0f, 0.0f, 0.0f, 1.0f);
            //glVertex2f(x1, y1);
            //glColor4f(1.0f, 0.0f, 0.0f, 1.0f);
            //glVertex2f(x2, y1);
            //glColor4f(1.0f, 0.0f, 0.0f, 1.0f);
            //glVertex2f(x2, y2);

            //glEnd(); // 사각형

            glfwSwapBuffers(window); //그림 그리는걸 다른데서 미리하고 버퍼스왑으로 가져옴? 그리는 과정 안보여짐
            glfwPollEvents(); // 이벤트를 계속 체크
        }
    private:
    };
}