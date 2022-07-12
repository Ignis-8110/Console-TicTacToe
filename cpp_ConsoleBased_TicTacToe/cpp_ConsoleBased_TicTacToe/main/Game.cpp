#include <iostream>
#include "Game.h"
#include "Player.h"

// 
void Game::Run() {
	while (!Game::GameOver()) {
		// do the game
		std::cout << Game::Get().m_CurrentMove << "\n";
		Game::Get().m_CurrentMove += 1;
	}
}

// checks if the game is over by checking if the board is filled using the board size.
bool Game::GameOver() {
	if (Game::Get().m_CurrentMove >= Game::Get().m_MaxMove) {
		return true;
	}
	return false;
}