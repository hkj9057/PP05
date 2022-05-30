#pragma once
#include <chrono>
#include <thread>
#include "Player.hpp"
#include "Enemy.hpp"
#include "JConsolManager.hpp"
#include <GLFW/glfw3.h>

using namespace std;

namespace JunSeok_Game
{
	class JGameLoop
	{
	private:
		GLFWwindow* window;
		bool _isGameRunning;
		JConsoleRenderer cRenderer;
		chrono::system_clock::time_point startRenderTimePoint;
		chrono::duration<double> renderDuration;
		Player Player;
		Enemy Enemy;

	public:
		JGameLoop() { _isGameRunning = false; }
		~JGameLoop() {}

	static void error_callback(int error, const char* description) // 에러뜨면 나올거
{
    fputs(description, stderr);
}
static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GL_TRUE);
}
		void Run()
		{
			_isGameRunning = true;
			Initialize();

			glfwSetErrorCallback(error_callback);
			if (!glfwInit())
				exit(EXIT_FAILURE);
			window = glfwCreateWindow(640, 480, "Simple example", NULL, NULL);
			if (!window)
			{
				glfwTerminate();
				exit(EXIT_FAILURE);
			}


			startRenderTimePoint = chrono::system_clock::now();
			while (_isGameRunning)
			{
				Input();
				Update();
				Render();
			}
			Release();
		}
		void Stop()
		{
			_isGameRunning = false;
		}
	private:
		void Initialize()
		{
		}
		void Release()
		{
		}
		void Input()
		{
			Player.isKeyPressed();
		}
		void Update()
		{

		}
		void Render()
		{
			cRenderer.Clear();

			cRenderer.MoveCursor(10, 20);// 프레임 위치

			renderDuration = chrono::system_clock::now() - startRenderTimePoint;
			startRenderTimePoint = chrono::system_clock::now();
			string fps = "FPS : " + to_string(1.0 / renderDuration.count());
			cRenderer.DrawString(fps);

			this_thread::sleep_for(chrono::milliseconds(20));
		}
	};
}