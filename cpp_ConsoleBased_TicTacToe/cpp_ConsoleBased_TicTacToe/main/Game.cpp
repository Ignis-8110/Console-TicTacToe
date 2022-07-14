#include <iostream>
#include "Game.h"
#include "Player.h"
#include "Board.h"
#include "Point.h"

Game::Game() : m_Player1('X', "Player 1"), m_Player2('O', "Player 2") {
	// initialize player 1 as the current player
	m_CurrentPlayer = &m_Player1;
}

void Game::Run() {
	while (!Game::GameOver()) {
		// do the game
		m_GameBoard.DrawBoard();
		std::cout << "\n" << m_CurrentPlayer->GetPlayerName() << " (" << m_CurrentPlayer->GetPlayerSymbol() << ") Turn\n\n";
		Point playerInput = m_GameBoard.HandleInput();
		if (m_GameBoard.IsMovePossible(playerInput)) {
			// pushes the current move to the collector
			m_GameBoard.m_MoveCollector.push_back(playerInput);
			m_CurrentMove++;
			// draws the board with the corresponding player symbol
			m_GameBoard.m_Board[playerInput.x-1][playerInput.y-1] = m_CurrentPlayer->GetPlayerSymbol();
			PlayerSwitchHandler();
		}
		else {
			std::cout << "Spot already taken. Please choose another one.\n";
		}
		system("pause");
		system("CLS");
	}
}

// checks if the game is over by checking if the amount of moves is greater than the possible max moves in a 3 x 3 grid
bool Game::GameOver() {
	if (m_CurrentMove >= m_MaxMove) {
		return true;
	}
	return false;
}

// switches the players; from player 1 to player2 and vice versa
// im using the symbols here to determine if the currentplayer is player 1 or 2
// i could've used an enum here but this also works
void Game::PlayerSwitchHandler() {
	switch (m_CurrentPlayer->GetPlayerSymbol()) {
	case 'X':
		m_CurrentPlayer = &m_Player2;
		break;
	case 'O':
		m_CurrentPlayer = &m_Player1;
		break;
	}
}