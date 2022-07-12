#include "Player.h"


Player::Player(char symbol) : m_Symbol(symbol), m_Point(0) {}

char Player::GetPlayerSymbol() {
	return m_Symbol;
}

void Player::AddPoint() {
	m_Point += 1;
}