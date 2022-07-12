#pragma once
class Player
{
public:

	Player(char symbol);
	void AddPoint();
	char GetPlayerSymbol();

private:

	int m_Point;
	char m_Symbol;

};

