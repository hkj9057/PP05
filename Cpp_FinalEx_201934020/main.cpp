#include "JGameLoop.hpp"

void main()
{
	JunSeok_Game::JGameLoop JGameLoop;
	srand(time(NULL));
	JGameLoop.GlRun();

	_CrtDumpMemoryLeaks();
} 
