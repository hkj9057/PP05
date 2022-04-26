#pragma once
#include <chrono>
#include <thread>
#include "MConsolUtil.hpp"
#include "Player.hpp"
#include "Monster.hpp"
using namespace std;

namespace MuSeoun_Engine
{
	class MGameLoop
	{
	private:
		bool _isGameRunning;
		MConsoleRenderer cRenderer;
		chrono::system_clock::time_point startRenderTimePoint;
		chrono::duration<double> renderDuration;
		Player p;
		Monster m;

	public:
		MGameLoop() { _isGameRunning = false; }
		~MGameLoop() {}

		void Run()
		{
			_isGameRunning = true;
			Initialize();

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
			//cRenderer.MoveCursor(p.x, p.y);
			//cRenderer.DrawString("-----Game Over-----");
		}
		void Input()
		{
			if (GetAsyncKeyState(VK_SPACE) & 0x8000 || GetAsyncKeyState(VK_SPACE) & 0x8001)
			{
				p.isKeyPressed();
			}
			else
			{
				p.isKeyUnpressed();
			}

		}
		void Update()
		{
		}
		void Render()
		{
			cRenderer.Clear();

			//cRenderer.MoveCursor(p.x, p.y);
			///cRenderer.DrawString("P");

			//cRenderer.MoveCursor(m.x, m.y);
			//cRenderer.DrawString("M");
			//m.x--;
			if (m.x == 20 && p.y == m.y)
			{
				cRenderer.MoveCursor(p.x, p.y);
				cRenderer.DrawString("-----Game Over-----");
			}
			else
			{
				cRenderer.MoveCursor(p.x, p.y);
				cRenderer.DrawString("P");

				cRenderer.MoveCursor(m.x, m.y);
				cRenderer.DrawString("M");
				m.x--;
			}
			if (m.x == 0)
			{
				m.x = 80;
			}

			cRenderer.MoveCursor(10, 20);

			renderDuration = chrono::system_clock::now() - startRenderTimePoint;
			startRenderTimePoint = chrono::system_clock::now();
			string fps = "FPS : " + to_string(1.0 / renderDuration.count());
			cRenderer.DrawString(fps);

			this_thread::sleep_for(chrono::milliseconds(20));
		}

		////cout << "Rendering speed : " << renderDuration.count() << "sec" << endl;

		//int remainingFrameTime = 100 - (int)(renderDuration.count() * 1000.0);
		//if (remainingFrameTime > 0)
		//	this_thread::sleep_for(chrono::milliseconds(remainingFrameTime));
	};
}