#include "Board.h"
#include "Square.h"
#include "Piece.h"
#include <iostream>

using namespace std;

void Board::createBoardSquare(int x, int y, bool checkered)
{
	boardLayout[x][y] = new Square (nullptr, checkered);
}

Board::Board()
{
	for (int y = 0; y < size; y++)
	{
		for (int x = 0; x < size; x++)
		{
			if ((x + y) % 2 == 1)
				createBoardSquare(x, y, true);
			else
				createBoardSquare(x, y, false);
		}
	}
}

void Board::displayBoard()
{
	char charSquare = 219;
	cout << endl << endl;
	for (int y = 7; y >= 0; y--)
	{
		cout << (y + 1) << "  ";
		for (int x = 0; x < 8; x++)
		{
			if (boardLayout[x][y]->isCheckered())
				cout << charSquare;
			else if (boardLayout[x][y]->getPiecePointer() != nullptr)
				cout << (boardLayout[x][y]->getPiecePointer())->uniqueID;
			else
				cout << ' ';
		}
		cout << endl;
	}
	cout << "   ABCDEFGH";
}

void Board::updateBoard(int x, int y, Piece* ptr)
{
	boardLayout[x][y]->setPiecePointer(ptr);
}

Piece* Board::getPiecePointer(int x, int y)
{
	return boardLayout[x][y]->getPiecePointer();
}