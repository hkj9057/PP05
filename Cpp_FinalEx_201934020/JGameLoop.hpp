#pragma once
#include <chrono>
#include <thread>
#include <crtdbg.h>
#include "Player.hpp"
#include "Enemy.hpp"
#include "RenderGlfw.hpp"
#include <GLFW/glfw3.h>
#include <math.h>

namespace JunSeok_Game
{
	class JGameLoop
	{
	bool _isGameRunning;
	bool _GameOver = true;
	Player Player;
	Enemy Enemy[10];
	RenderGlfw RenderGlfw;

	public:
		JGameLoop() { _isGameRunning = false; }
		~JGameLoop() {}
		

		void GlRun()
		{
			RenderGlfw.GlfwStart();
			Initialize();
			while (_isGameRunning)
			{
				if (_GameOver)
				{
					Input();
					Update();
					Render();
				}
				ReStart();
			}
			RenderGlfw.EndGlfw();
		}


		void Collision(float p_x, float p_y, float e_x, float e_y)
		{
			if (((p_y - 0.037) < (e_y + 0.037)) && ((p_y + 0.037) > (e_y - 0.037)))
			{
				if (((p_x - 0.037) < (e_x + 0.037)) && ((p_x + 0.037) > (e_x - 0.037)))
					_GameOver = false;
			}
			//float length = 0.04f;
			//float dis = sqrt(((p_y - e_y) * (p_y - e_y)) + ((p_x - e_x) * (p_x - e_x)));
			//
			//if (length > dis)
			//{
			//	cout << "출돌"; // _GameOver = false
			//} // 점이 원이면
		}

		void ReStart()
		{
			if (GetAsyncKeyState(VK_SPACE) & 0x8000 || GetAsyncKeyState(VK_SPACE) & 0x8001)
			{
				_GameOver = true;
				Initialize();
			}
			else if (GetAsyncKeyState(VK_SHIFT) & 0x8000 || GetAsyncKeyState(VK_SHIFT) & 0x8001)
			{
				_isGameRunning = false;
			}
		}

	private:
		void Initialize()
		{
			Player.PlayerInitialize();
			for (int i = 0; i < 10; i++)
			{
				Enemy[i].EnemyInitialize();
			}
			_isGameRunning = true;

			for (int i = 0; i < 10; i++)
			{
				Enemy[i].YPoint = 0.85f - (i * 0.2f);
			}
		}

		void Input()
		{
			Player.isKeyPressed();
			if (Player.XPoint >= 1.0f)
			{
				Player.XPoint = 1.0f;
			}
			if (Player.XPoint <= -1.0f)
			{
				Player.XPoint = -1.0f;
			}
			if (Player.YPoint <= -1.0f)
			{
				Player.YPoint = -1.0f;
			}
			if (Player.YPoint >= 1.0f)
			{
				Player.YPoint = 1.0f;
			}

		}

		void Update()
		{
			for (int i = 0; i < 10; i++)
			{
				Enemy[i].EnemyMove();
				Collision(Player.XPoint, Player.YPoint,
					Enemy[i].XPoint, Enemy[i].YPoint);
			}
		}

		void Render()
		{
			RenderGlfw.Draw(Player.XPoint, Player.YPoint, 0.0f);
			for (int i = 0; i < 10; i++)
			{
				RenderGlfw.Draw(Enemy[i].XPoint, Enemy[i].YPoint, 1.0f);
			}
			
			RenderGlfw.SwapBuffer();
		}

	};
}