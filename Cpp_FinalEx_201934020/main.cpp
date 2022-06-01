#include "JGameLoop.hpp"

void main()
{
	JunSeok_Game::JGameLoop JGameLoop;
	srand(time(NULL));
	JGameLoop.Run();

	_CrtDumpMemoryLeaks();
} // Ãæµ¹ ,
