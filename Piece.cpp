#include "Piece.h"

Piece::Piece(int x, int y, bool player1, char uniqueID)
{
	this->x = x;
	this->y = y;
	this->player1 = player1;
	this->uniqueID = uniqueID;
}

bool Piece::isPlayer1()
{
	return player1;
}

bool Piece::isKing()
{
	return king;
}

void Piece::promoteKing()
{
	king = true;
}