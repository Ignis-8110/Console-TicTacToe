#pragma once
#include <iostream>
#include <vector>
#include "Player.h"
#include "Board.h"
#include "Point.h"

class Game
{
public:
	Game(const Game&) = delete;
	Game();
	void Run();
	bool GameOver();
	void PlayerSwitchHandler();
	int m_CurrentMove = 0;

	bool CheckColumns();
	bool CheckRows();
	bool CheckDiagonals();
	bool CheckSymbols(const std::vector<char>& container);

private:


	int m_MaxMove = 9;
	Board m_GameBoard;

	Player m_Player1;
	Player m_Player2;
	Player* m_CurrentPlayer;
	Player* m_PreviousPlayer;
	
};

