#ifndef SQUARE_H
#define SQUARE_H

class Piece;

class Square
{
	
private:
	Piece* ptr;
	bool checkered;

public:
	Square(Piece* ptr, bool checkered);
	bool isCheckered();
	Piece* getPiecePointer();
	void setPiecePointer(Piece* ptr);
	
};

#endif