#include "Player.h"


Player::Player(char symbol, std::string name) : m_Symbol(symbol), m_Point(0), m_Name(name) {}

char Player::GetPlayerSymbol() {
	return m_Symbol;
}


void Player::AddPoint() {
	m_Point += 1;
}

std::string Player::GetPlayerName() {
	return m_Name;
}