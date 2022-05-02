#include "Player.h"

Player::Player(int x)
{
	this->playerNum = x;
}

void Player::setPlayerChar(char playerChar)
{ 
	this->playerChar = playerChar;
}

char Player::getPlayerChar()
{
	return this->playerChar;
}