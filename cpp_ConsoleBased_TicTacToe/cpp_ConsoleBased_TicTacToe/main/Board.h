#pragma once
#include "Point.h"
#include "Player.h"
#include <vector>
class Board
{
public:
	Board();

	void DrawBoard();
	bool IsMovePossible(const Point& pt);
public:
	static const int m_BoardHeight = 3;
	static const int m_BoardWidth = 3;

public:
	
	// this variable is responsible to stop the other player from putting their symbol from an existing player symbol
	std::vector<Point> m_MoveCollector;
	char m_Board[m_BoardHeight][m_BoardWidth];

	Point HandleInput();
	void GenerateBoard();
	void CheckNumber(bool input);

	
};

