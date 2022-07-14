#pragma once
#include "Player.h"
#include "Board.h"
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

private:


	int m_MaxMove = 9;
	Board m_GameBoard;

	Player m_Player1;
	Player m_Player2;
	Player* m_CurrentPlayer;


};

