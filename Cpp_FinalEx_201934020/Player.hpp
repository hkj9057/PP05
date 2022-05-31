#pragma once
#include <Windows.h>

namespace JunSeok_Game
{
	class Player
	{
	public:
		float Player_XPoint;
		float Player_YPoint;
		Player()
		{
			 Player_XPoint = 0.0f;
			 Player_YPoint = 0.0f;
		}
		~Player()
		{}
		void isKeyPressed()
		{
			if (GetAsyncKeyState(VK_LEFT) & 0x8000 || GetAsyncKeyState(VK_LEFT) & 0x8001)
			{
				Player_XPoint -= 0.009;
				
			}
			else if (GetAsyncKeyState(VK_RIGHT) & 0x8000 || GetAsyncKeyState(VK_RIGHT) & 0x8001)
			{
				Player_XPoint += 0.009;
			}
			if (GetAsyncKeyState(VK_UP) & 0x8000 || GetAsyncKeyState(VK_UP) & 0x8001)
			{
				Player_YPoint += 0.009;
			}
			else if (GetAsyncKeyState(VK_DOWN) & 0x8000 || GetAsyncKeyState(VK_DOWN) & 0x8001)
			{
				Player_YPoint -= 0.009;
			}
		}
	};
}
