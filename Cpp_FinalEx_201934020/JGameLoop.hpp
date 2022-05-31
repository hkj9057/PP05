#pragma once
#include <chrono>
#include <thread>
#include <crtdbg.h>
#include "Player.hpp"
#include "Enemy.hpp"
#include "JConsolManager.hpp"
#include "RenderGlfw.hpp"
#include <GLFW/glfw3.h>


namespace JunSeok_Game
{
	class JGameLoop
	{
	//GLFWwindow* window;
	bool _isGameRunning;
	JConsoleRenderer cRenderer;
	//chrono::system_clock::time_point startRenderTimePoint;
	//chrono::duration<double> renderDuration;
	Player Player;
	Enemy Enemy;
	RenderGlfw RenderGlfw;

	public:
		JGameLoop() { _isGameRunning = false; }
		~JGameLoop() {}
		void Collision(float p_x, float p_y, float e_x, float e_y)
		{
			if (p_x == e_x && p_y == e_y)  _isGameRunning = false;
		}
		void ReStart()
		{
			if (GetAsyncKeyState(VK_SPACE) & 0x8000 || GetAsyncKeyState(VK_SPACE) & 0x8001)
			{
				_isGameRunning = true;
			}
		}

		void Run()
		{
			_isGameRunning = true;
			Initialize();
			RenderGlfw.GlfwStart();

			//startRenderTimePoint = chrono::system_clock::now();
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
			RenderGlfw.EndGlfw();
		}
		void Input()
		{
			Player.isKeyPressed();
		}
		void Update()
		{
			//cout << "������";
		}
		void Render()
		{
			RenderGlfw.Draw(Player.Player_XPoint, Player.Player_YPoint, 0.0f);
			RenderGlfw.Draw(Enemy.Enemy_XPoint, Enemy.Enemy_YPoint, 1.0f);
			RenderGlfw.SwapBuffer();
		}//���ʹ� ��ǥ���� �������� �ޱ�, ���ʹ̿��ʹ̴� ��� �����Ǿ��ϴϱ� �迭�� ���� �־��ֱ�, �浹�Լ� �����ϱ�
	};
}