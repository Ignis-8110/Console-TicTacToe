#include "Board.h"
#include <iostream>
#include "Game.h"

Board::Board() :m_Player1('X'), m_Player2('O') {
	GenerateBoard();
}

// checks if the current input by the player is within the bounds of the grid and the point is blank
bool Board::IsMovePossible(const Point& pt) {

	for (const Point& point : m_MoveCollector) {
		if (pt == point) {
			return false;
		}
	}
	m_MoveCollector.push_back(pt);
	Game::Get().m_CurrentMove++;
	return true;
}

// generates a blank 3 x 3 grid
void Board::GenerateBoard() {
	for (int x = 0; x < m_BoardHeight; x++) {
		for (int y = 0; y <m_BoardWidth; y++) {
			m_Board[x][y] = ' ';
		}
	}
}

// checks the x and y input from the player
Point Board::HandleInput() {
	bool inputsCorrect = false;
	int x, y;
	std::cout << "Please Choose a location.\n";		
	
	do {
		std::cout << "Enter the X: ";
		CheckNumber((bool)(std::cin >> x));
		std::cout << "Enter the Y: ";
		CheckNumber((bool)(std::cin >> y));
		if ((x > 0 && x <= m_BoardWidth) && (y > 0 && y <= m_BoardHeight)) {
			inputsCorrect = true;
		}
		else {
			system("cls");
			std::cout << "Please Enter a valid Number within 0 - 3\n";
			inputsCorrect = false;
		}
		
	} while (!inputsCorrect);

	if (inputsCorrect) {
		return Point(x, y);
	}
}

// checks if the input is an int or not
void Board::CheckNumber(bool input) {
	if (!input) {
		std::cout << "Please enter numbers only.\n";
		std::cin.clear();
		std::cin.ignore(1000, '\n');
	}
}

void Board::DrawBoard() {

	std::cout << "X\n";
	for (int x = 0; x < m_BoardHeight; x++) {
		std::cout << x+1 << " | ";
		for (int y = 0; y < m_BoardWidth; y++) {
			std::cout  << m_Board[x][y] << " | ";
		}
		std::cout << "\n";
	}
	Point playerInput = HandleInput();
	if (IsMovePossible(playerInput)) {
		m_Board[playerInput.x -1][playerInput.y - 1] = '2';
	}
	else {
		std::cout << "Spot already taken. Please choose another one.\n";
	}
	system("pause");
	system("CLS");
}