#include <GLFW/glfw3.h> //�׷��� ���̺귯�� �����ӿ�ũ
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
            window = glfwCreateWindow(640, 480, "Simple example", NULL, NULL);// ������â ����
            if (!window)
            {
                glfwTerminate();
                exit(EXIT_FAILURE);
            }
            glfwMakeContextCurrent(window); //Context�� ���, gpu���� , conext = Ŭ��������?    s = ������ = ���ÿ� �������� ������
            glfwSetKeyCallback(window, key_callback);

            float ratio;
            int width, height;
            glfwGetFramebufferSize(window, &width, &height); //framebuffer = ȭ�鿡 ����� �޸� ����?
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

            glClearColor(1.0f, 1.0f, 0.0f, 1.0f); // ȭ���� �Ѱ��� ������ ä���(Ŭ�����ϰڴ�)
            glClear(GL_COLOR_BUFFER_BIT);

            glPointSize(20);
            glBegin(GL_POINTS); // ��(�÷��̾�)

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

            //glEnd(); // �簢��

            glfwSwapBuffers(window); //�׸� �׸��°� �ٸ����� �̸��ϰ� ���۽������� ������? �׸��� ���� �Ⱥ�����
            glfwPollEvents(); // �̺�Ʈ�� ��� üũ
        }
    private:
    };
}