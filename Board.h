#ifndef BOARD_H
#define BOARD_H
class Square;
class Piece;

class Board
{
public:
	const static int size = 8;
	Board();
	void createBoardSquare(int x, int y, bool checkered);
	void setPiecePointer();
	Piece* getPiecePointer(int x, int y);
	void displayBoard();
	void updateBoard(int x, int y, Piece* ptr);

private:
	Square* boardLayout[size][size];
};

#endif