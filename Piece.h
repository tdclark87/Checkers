#ifndef PIECE_H
#define PIECE_H


class Piece
{
private:
	int x, y;							// x and y coordinates for each piece
	bool king = false;				// default is false
	bool player1;
	

public:
	char uniqueID;										//for testing purposes
	Piece(int x, int y, bool isBlack, char uniqueID);   //Constructor for Piece objects, where x and y are coordinates and boolean for color
	bool isPlayer1();
	bool isKing();
	void promoteKing();
};

#endif
