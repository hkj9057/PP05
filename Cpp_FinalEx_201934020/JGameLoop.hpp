#pragma once
#include <chrono>
#include <thread>
#include "Player.hpp"
#include "Enemy.hpp"
#include "JConsolManager.hpp"
#include "RenderGlfw.hpp"
#include <GLFW/glfw3.h>

namespace JunSeok_Game
{
	class JGameLoop
	{
	
	GLFWwindow* window;
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
			cout << "½ÇÇàÁß";
		}
		void Render()
		{
			RenderGlfw.Draw(Player.Player_XPoint, Player.Player_YPoint);
		}
	};
}