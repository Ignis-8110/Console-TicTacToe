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

	int m_CurrentMove = 0;

private:

	Game() {}
	int m_MaxMove = 9;

};

