#include "Square.h"

Square::Square(Piece* ptr, bool checkered)
{
	this->ptr = ptr;
	this->checkered = checkered;
}


bool Square::isCheckered()
{
	return checkered;
}

Piece* Square::getPiecePointer()
{
	return ptr;
}

void Square::setPiecePointer(Piece* ptr)
{
	this->ptr = ptr;
}