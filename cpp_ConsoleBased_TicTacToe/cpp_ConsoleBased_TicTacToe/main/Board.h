#pragma once
#include "Point.h"
#include <vector>
class Board
{
public:
	Board();

	void DrawBoard();
	bool IsMovePossible(const Point& pt);
private:
	static const int m_BoardHeight = 3;
	static const int m_BoardWidth = 3;

	std::vector<Point> m_MoveCollector;
	char m_Board[m_BoardHeight][m_BoardWidth];

	Point HandleInput();
	void GenerateBoard();
	void CheckNumber(bool input);

	class Player m_Player1;
	class Player m_Player2;
	class Player* m_CurrentPlayer;

};

