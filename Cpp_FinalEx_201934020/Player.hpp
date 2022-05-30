#pragma once
#include <Windows.h>

namespace JunSeok_Game
{
	class Player
	{
	public:
		float Player_XPoint1;
		float Player_XPoint2;
		float Player_YPoint1;
		float Player_YPoint2;
		Player()
		{
			float Player_XPoint1 = -0.1f;
			float Player_XPoint2 = 0.2f;
			float Player_YPoint1 = -0.1f;
			float Player_YPoint2 = 0.2f;
		}
		~Player()
		{}
		void isKeyPressed()
		{
			if (GetAsyncKeyState(VK_LEFT) & 0x8000 || GetAsyncKeyState(VK_LEFT) & 0x8001)
			{
				Player_XPoint1 -= 0.003;
				Player_XPoint2 -= 0.003;
			}
			else if (GetAsyncKeyState(VK_RIGHT) & 0x8000 || GetAsyncKeyState(VK_RIGHT) & 0x8001)
			{
				Player_XPoint1 += 0.003;
				Player_XPoint2 += 0.003;
			}
			if (GetAsyncKeyState(VK_UP) & 0x8000 || GetAsyncKeyState(VK_UP) & 0x8001)
			{
				Player_YPoint1 += 0.003;
				Player_YPoint2 += 0.003;
			}
			else if (GetAsyncKeyState(VK_DOWN) & 0x8000 || GetAsyncKeyState(VK_DOWN) & 0x8001)
			{
				Player_YPoint1 -= 0.003;
				Player_YPoint2 -= 0.003;
			}
		}
	};

}
