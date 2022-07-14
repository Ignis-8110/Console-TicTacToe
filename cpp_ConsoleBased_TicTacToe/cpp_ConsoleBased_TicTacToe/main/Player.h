#pragma once
#include <string>
class Player
{
public:

	Player(char symbol, std::string name);
	void AddPoint();
	char GetPlayerSymbol();
	std::string GetPlayerName();

private:

	int m_Point;
	char m_Symbol;
	std::string m_Name;

};

