#include <GLFW/glfw3.h> //�׷��� ���̺귯�� �����ӿ�ũ
#include <stdlib.h>
#include <stdio.h>
#include <Windows.h>
#include <iostream>

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
    float boxPointy1 = 0.7f;
    float boxPointy2 = 0.0;;
    float boxPointx1 = -0.7f;
    float boxPointx2 = 0.0;;

    float moveBoxPointx1 = 0.8f;
    float moveBoxPointx2 = 0.6f;
    float moveBoxPointy1 = 0.15f;
    float moveBoxPointy2 = 0.0f;

    glfwSetErrorCallback(error_callback);
    if (!glfwInit())
        exit(EXIT_FAILURE);
    window = glfwCreateWindow(640, 480, "Simple example", NULL, NULL);
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

    while (!glfwWindowShouldClose(window))
    {
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE);

        glClearColor(1.0f, 0.0f, 0.0f, 1.0f); // ȭ���� �Ѱ��� ������ ä���(Ŭ�����ϰڴ�)
        glClear(GL_COLOR_BUFFER_BIT);

        if (GetAsyncKeyState(VK_LEFT) & 0x8000 || GetAsyncKeyState(VK_LEFT) & 0x8001)
        {
            moveBoxPointx1 -= 0.03;
            moveBoxPointx2 -= 0.03;
        }
        else if(GetAsyncKeyState(VK_RIGHT) & 0x8000 || GetAsyncKeyState(VK_RIGHT) & 0x8001)
        {
            moveBoxPointx1 += 0.03;
            moveBoxPointx2 += 0.03;
        }
        if (GetAsyncKeyState(VK_UP) & 0x8000 || GetAsyncKeyState(VK_UP) & 0x8001)
        {
            moveBoxPointy1 += 0.03;
            moveBoxPointy2 += 0.03;
        }
        else if (GetAsyncKeyState(VK_DOWN) & 0x8000 || GetAsyncKeyState(VK_DOWN) & 0x8001)
        {
            moveBoxPointy1 -= 0.03;
            moveBoxPointy2 -= 0.03;
        }

        glPointSize(10);
        glBegin(GL_TRIANGLES);

        glColor4f(1.0f, 1.0f, 0.0f, 1.0f);
        glVertex2f(boxPointx1, boxPointy1);
        glColor4f(1.0f, 1.0f, 0.0f, 1.0f);
        glVertex2f(boxPointx1, boxPointy2);
        glColor4f(1.0f, 1.0f, 0.0f, 1.0f);
        glVertex2f(boxPointx2, boxPointy2);

        glEnd();

        glPointSize(10);
        glBegin(GL_TRIANGLES);

        glColor4f(1.0f, 1.0f, 0.0f, 1.0f);
        glVertex2f(boxPointx1, boxPointy1);
        glColor4f(1.0f, 1.0f, 0.0f, 1.0f);
        glVertex2f(boxPointx2, boxPointy1);
        glColor4f(1.0f, 1.0f, 0.0f, 1.0f);
        glVertex2f(boxPointx2, boxPointy2);

        glEnd(); // �簢��
        
        glPointSize(5); // �����̴� �簢��
        glBegin(GL_TRIANGLES);

        glColor4f(1.0f, 0.0f, 1.0f, 1.0f);
        glVertex2f(moveBoxPointx2, moveBoxPointy2);
        glColor4f(1.0f, 0.0f, 1.0f, 1.0f);
        glVertex2f(moveBoxPointx1, moveBoxPointy2);
        glColor4f(1.0f, 0.0f, 1.0f, 1.0f);
        glVertex2f(moveBoxPointx1, moveBoxPointy1);

        glEnd();

        glPointSize(5);
        glBegin(GL_TRIANGLES);

        glColor4f(1.0f, 0.0f, 1.0f, 1.0f);
        glVertex2f(moveBoxPointx2, moveBoxPointy1);
        glColor4f(1.0f, 0.0f, 1.0f, 1.0f);
        glVertex2f(moveBoxPointx1, moveBoxPointy1);
        glColor4f(1.0f, 0.0f, 1.0f, 1.0f);
        glVertex2f(moveBoxPointx2, moveBoxPointy2);

        glEnd();

        //if (xPoint < -1.0f)
        //    xPoint = 0.8f;
        //else
         //   xPoint = xPoint - 0.02f;
       // if (xPoint2 < -1.2f)
         //   xPoint2 = 0.6f;
        //else
          //  xPoint2 = xPoint2 - 0.02f;
        if (moveBoxPointx2 < boxPointx2 && moveBoxPointx2 > boxPointx1 &&
            moveBoxPointy2 > boxPointy2 && moveBoxPointy2 < boxPointy1) std::cout << "��Ҵ�.";
        if (moveBoxPointx1 < boxPointx2 && moveBoxPointx1 > boxPointx1 &&
            moveBoxPointy1 > boxPointy2 && moveBoxPointy1 < boxPointy1) std::cout << "��Ҵ�.";
        if (moveBoxPointx1 < boxPointx2 && moveBoxPointx1 > boxPointx1 &&
            moveBoxPointy2 > boxPointy2 && moveBoxPointy2 < boxPointy1) std::cout << "��Ҵ�.";
        if (moveBoxPointx2 < boxPointx2 && moveBoxPointx1 > boxPointx1 &&
            moveBoxPointy1 > boxPointy2 && moveBoxPointy2 < boxPointy1) std::cout << "��Ҵ�.";
        
        
       

        glfwSwapBuffers(window); //�׸� �׸��°� �ٸ����� �̸��ϰ� ���۽������� ������? �׸��� ���� �Ⱥ�����
        glfwPollEvents(); // �̺�Ʈ�� ��� üũ
    }
    glfwDestroyWindow(window);
    glfwTerminate();
    exit(EXIT_SUCCESS);
}