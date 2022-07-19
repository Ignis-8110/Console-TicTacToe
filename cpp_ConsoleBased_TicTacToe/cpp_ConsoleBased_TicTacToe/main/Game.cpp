#include "Game.h"

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
	if (CheckRows() || CheckColumns() || CheckDiagonals()) {
		std::cout << m_PreviousPlayer->GetPlayerName() << " Won!\n";
		return true;
	}


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
		m_PreviousPlayer = m_CurrentPlayer;
		m_CurrentPlayer = &m_Player2;
		break;
	case 'O':
		m_PreviousPlayer = m_CurrentPlayer;
		m_CurrentPlayer = &m_Player1;
		break;
	}
}


bool Game::CheckColumns() {
	for (int x = 0; x < 3; x++) {
		// the first condition checks if the symbol is the player's corresponding symbols
		// checks if the columns are the same, or we got 3 adjacent symbols
		if ((m_GameBoard.m_Board[0][x] == m_Player1.GetPlayerSymbol() 
			|| m_GameBoard.m_Board[0][x] == m_Player2.GetPlayerSymbol())
			&& (m_GameBoard.m_Board[0][x] == m_GameBoard.m_Board[1][x])
			&& (m_GameBoard.m_Board[0][x] == m_GameBoard.m_Board[2][x])) {
			std::cout << "COLUMN\n";
			return true;
		}
	}
	return false;
}
bool Game::CheckRows() {
	for (int x = 0; x < 3; x++) {
		// the first condition checks if the symbol is the player's corresponding symbols
		// checks if the rows are the same, or we got 3 adjacent symbols
		if ((m_GameBoard.m_Board[x][0] == m_Player1.GetPlayerSymbol() 
			|| m_GameBoard.m_Board[x][0] == m_Player2.GetPlayerSymbol())
			&& (m_GameBoard.m_Board[x][0] == m_GameBoard.m_Board[x][1])
			&& (m_GameBoard.m_Board[x][0] == m_GameBoard.m_Board[x][2])) {
			std::cout << "ROW\n";
			return true;
		}
	}
	return false;
}

// Checks the left and right diagonal symbols.
// this function is scalable depending on the size of the grid
bool Game::CheckDiagonals() {
	std::vector<char> rDiagCollector;
	std::vector<char> lDiagCollector;
	for (int x = 0; x < 3; x++) {

		// checks the left diagonal symbols
		if (m_GameBoard.m_Board[0][0] == m_Player1.GetPlayerSymbol()
			|| m_GameBoard.m_Board[0][0] == m_Player2.GetPlayerSymbol()) {
			for (int i = 0; i < m_GameBoard.m_BoardHeight; i++) {
				lDiagCollector.push_back(m_GameBoard.m_Board[i][i]);
			}
			if (CheckSymbols(lDiagCollector)) {
				std::cout << "LEFT DIAG\n";
				return true;
			}
		}

		// checks the right diagonal symbols
		if (m_GameBoard.m_Board[0][m_GameBoard.m_BoardHeight - 1] == m_Player1.GetPlayerSymbol()
			|| m_GameBoard.m_Board[0][m_GameBoard.m_BoardHeight - 1] == m_Player2.GetPlayerSymbol()) {
			for (int i = 0; i < m_GameBoard.m_BoardHeight; i++) {
				rDiagCollector.push_back(m_GameBoard.m_Board[(m_GameBoard.m_BoardHeight - 1) - i][i]);
			}
			if (CheckSymbols(rDiagCollector)) {
				std::cout << "RIGHT DIAG\n";
				return true;
			}
		}

		return false;
	}
}
bool Game::CheckSymbols(const std::vector<char>& container){
	for (auto& symbol : container) {
		if (symbol != m_PreviousPlayer->GetPlayerSymbol()) {
			return false;
		}
	}
	return true;
}