#pragma once
#include <Windows.h>
#include <iostream>
#include <cstdlib>
#include <ctime>

namespace JunSeok_Game
{
	class Enemy
	{
	public:
		float Enemy_XPoint;
		float Enemy_YPoint;
		float Enemy_Speed;

		Enemy()
		{
			Enemy_XPoint = 0.9f;
			Enemy_YPoint = 0.0f;
			Enemy_Speed = 0.09;
		}
		~Enemy()
		{}

		//rand() = 난수 생성(대충 0~351364)
		
		//Player()
		//{
			//float Player_XPoint1 = -0.1f;
			//float Player_XPoint2 = 0.2f;
			//float Player_YPoint1 = -0.1f;
			//float Player_YPoint2 = 0.2f;
		//}
		//~Player()
		//{}
	};

}
