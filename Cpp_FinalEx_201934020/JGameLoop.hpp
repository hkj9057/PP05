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
	float arrayDown = 0.0f;

	public:
		JGameLoop() { _isGameRunning = false; }
		~JGameLoop() {}
		void Collision(float p_x, float p_y, float e_x, float e_y)
		{
			//if (GetAsyncKeyState(VK_BACK) & 0x8000 || GetAsyncKeyState(VK_BACK) & 0x8001)
			//{
				//_GameOver = false;
			//}
		

			if (((p_y - 0.02) < (e_y + 0.02)) && ((p_y + 0.02) > (e_y - 0.02)))
			{
				if (((p_x - 0.02) < (e_x + 0.02)) && ((p_x + 0.02) > (e_x - 0.02)))
					 _GameOver = false;
			}

			//float length = 0.04f;
			//float dis = sqrt(((p_y - e_y) * (p_y - e_y)) + ((p_x - e_x) * (p_x - e_x)));
			//
			//if (length > dis)
			//{
			//	cout << "Ãâµ¹"; // _GameOver = false
			//}
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

		void Run()
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
			/*while (true)
			{
				while (_isGameRunning)
				{
					Input();
					Update();
					Render();
				}
				ReStart();
			}*/
			Release();
		}

		void Stop()
		{
			_isGameRunning = false;
		}

	private:
		void Initialize()
		{
			Player.PlayerInInitialize();
			for (int i = 0; i < 10; i++)
			{
				Enemy[i].EnEmyInInitialize();
			}
			_isGameRunning = true;

			for (int i = 0; i < 10; i++)
			{
				Enemy[i].YPoint = 0.85f - (i * 0.2f);
			}
		}

		void Release()
		{
			RenderGlfw.EndGlfw();
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
			//for (int i = 0; i < 10; i++)
			//{
				//RenderGlfw.Draw(Enemy[i].XPoint, Enemy[i].YPoint - arrayDown, 1.0f);
				//arrayDown -= 0.2f;
			//}
			RenderGlfw.Draw(Enemy[0].XPoint, Enemy[0].YPoint, 1.0f);
			RenderGlfw.Draw(Enemy[1].XPoint, Enemy[1].YPoint , 1.0f);
			RenderGlfw.Draw(Enemy[2].XPoint, Enemy[2].YPoint, 1.0f);
			RenderGlfw.Draw(Enemy[3].XPoint, Enemy[3].YPoint, 1.0f);
			RenderGlfw.Draw(Enemy[4].XPoint, Enemy[4].YPoint, 1.0f);
			RenderGlfw.Draw(Enemy[5].XPoint, Enemy[5].YPoint, 1.0f);
			RenderGlfw.Draw(Enemy[6].XPoint, Enemy[6].YPoint, 1.0f);
			RenderGlfw.Draw(Enemy[7].XPoint, Enemy[7].YPoint, 1.0f);
			RenderGlfw.Draw(Enemy[8].XPoint, Enemy[8].YPoint, 1.0f);
			RenderGlfw.Draw(Enemy[9].XPoint, Enemy[9].YPoint, 1.0f);
			
			RenderGlfw.SwapBuffer();
		}

	};
}