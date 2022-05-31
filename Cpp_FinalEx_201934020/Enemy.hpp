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
		/*void isKeyPressed()
		{
			if (GetAsyncKeyState(VK_LEFT) & 0x8000 || GetAsyncKeyState(VK_LEFT) & 0x8001)
			{
				Player_XPoint1 -= 0.07;
				Player_XPoint2 -= 0.07;
			}
			else if (GetAsyncKeyState(VK_RIGHT) & 0x8000 || GetAsyncKeyState(VK_RIGHT) & 0x8001)
			{
				Player_XPoint1 += 0.07;
				Player_XPoint2 += 0.07;
			}
			if (GetAsyncKeyState(VK_UP) & 0x8000 || GetAsyncKeyState(VK_UP) & 0x8001)
			{
				Player_YPoint1 += 0.07;
				Player_YPoint2 += 0.07;
			}
			else if (GetAsyncKeyState(VK_DOWN) & 0x8000 || GetAsyncKeyState(VK_DOWN) & 0x8001)
			{
				Player_YPoint1 -= 0.07;
				Player_YPoint2 -= 0.07;
			}
		}*/
	};

}
