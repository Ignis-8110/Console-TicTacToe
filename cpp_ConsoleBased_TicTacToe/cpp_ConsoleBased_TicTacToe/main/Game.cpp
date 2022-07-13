#include <iostream>
#include "Game.h"
#include "Player.h"
#include "Board.h"

void Game::Run() {
	Board brd;
	while (!Game::GameOver()) {
		// do the game
		brd.DrawBoard();
		
	}
}

// checks if the game is over by checking if the board is filled using the board size.
bool Game::GameOver() {
	if (Game::Get().m_CurrentMove >= Game::Get().m_MaxMove) {
		return true;
	}
	return false;
}