#pragma once
#include "Player.h"
class Game
{
public:
	Game(const Game&) = delete;

	// returns the a singleton of Game
	static Game& Get() {
		static Game instance;
		return instance;
	}
	static void Run();

	static bool GameOver();

private:
	Game() : pl1('X'), pl2('O') {}
	class Player pl1;
	class Player pl2;
	int m_MaxMove = 9;
	int m_CurrentMove = 0;
};

