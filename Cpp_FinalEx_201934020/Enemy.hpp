#pragma once
#include <Windows.h>
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

namespace JunSeok_Game
{
	class Enemy
	{
	public:
		float XPoint;
		float YPoint;
		float Enemy_Speed;

		Enemy()
		{
			XPoint = 0.9f;
			YPoint = 0.85f;
			Enemy_Speed = (float)(rand() % 10) / 1000 + 0.001f;
			cout << Enemy_Speed;
		}
		~Enemy()
		{}

		void EnemyMove()
		{
			XPoint -= Enemy_Speed;
			if (XPoint < -1.0f) XPoint = 0.9f;
		}
		void EnEmyInInitialize()
		{
			XPoint = 0.9f;
			YPoint = 0.85f;
			Enemy_Speed = (float)(rand() % 10) / 1000 + 0.001f;
			cout << Enemy_Speed;
		}
		
	};

}
