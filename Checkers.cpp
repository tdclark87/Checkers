#include "Checkers.h"
#include "Board.h"
#include "Square.h"
#include "Piece.h"

#include <vector>
#include <string>
#include <stdlib.h> 
#include <ctype.h>

Checkers::Checkers()
{
	pBoard = new Board();
}

void Checkers::createCheckerPieces()
{
	char id = 'a';
	char id2 = 'm';
	int size = 8;
	for (int y = size - 1; y >= 0; y--)
	{
		for (int x = 0; x < size; x++)
		{
			if ((x + y) % 2 == 0)
			{
				if (y < 3)
				{
					pBoard->updateBoard(x, y, new Piece(x, y, true, id));
					id++;
				}
				else if (y >= (8 - 3))
				{
					pBoard->updateBoard(x , y, new Piece(x, y, false, id2));
					id2++;
				}
			}
		}
	}

}

void Checkers::displayBoard()
{
	pBoard->displayBoard();
}

void Checkers::movePiece(int x, int y, int a, int b)
{
	pBoard->updateBoard(a, b, pBoard->getPiecePointer(x, y));
	pBoard->updateBoard(x, y, nullptr);
}

void Checkers::deletePiece(int x, int y)
{
	delete (pBoard->getPiecePointer(x, y));
	pBoard->updateBoard(x, y, nullptr);
}

bool Checkers::moveCheckPiece(bool player, std::vector<int> moves)
{
	return player == ((pBoard->getPiecePointer(moves[0], moves[1]))->isPlayer1());
}

std::string Checkers::moveCheck(bool player, std::vector<int> moves)
{
	Piece* piece1 = pBoard->getPiecePointer(moves[0], moves[1]);
	Piece* piece2;

	if (piece1 == nullptr)
		return "The first coordinate does not have a piece there to move.";
	if(piece1->isPlayer1() != player)					//Checks player is moving their own piece
		return "You don't have a piece at the first coordinate.";
	if ((moves.size() % 2 == 1) || moves.size()<4)		//Checks that you have even number of coordinates
		return "Need both a letter and a number for each position.";
	for (int i = 0; i < moves.size() - 2; i = i + 2)	// Loop over coordinate pairs
	{
		piece2 = pBoard->getPiecePointer(moves[i+2], moves[i + 3]);
		
		if (piece2 != nullptr)
			return "You can't move there because a piece is already there.";  // Checks for piece in landing spot
		if (not piece1->isKing())
		{
			if ((moves[i + 1] - moves[i + 3] > 0 && player))
				return "Only kings can move backwards.";
			if (moves[i + 1] - moves[i + 3] < 0 && not player)
				return "Only kings can move backwards.";					//This checks that piece is going in right direction
		}
		if ((abs(moves[i] - moves[i + 2]) == 2) && (abs(moves[i + 1] - moves[i + 3])) == 2)
		{
			Piece* piece3 = pBoard->getPiecePointer((moves[i] + moves[i + 2]) / 2, (moves[i + 1] + moves[i + 3]) / 2);
			if (piece3 == nullptr)
				return "If you are moving two spaces, you have to jump a piece.";  
			else if (piece3->isPlayer1() == player)
				return "If you are moving two spaces, you have to jump your opponent's piece.";
		}
		if (i > 1 && ((abs(moves[i] - moves[i + 2]) == 1) && (abs(moves[i + 1] - moves[i + 3])) == 1))
			return "All of your moves after the first must be jumps.";
		if ((abs(moves[i] - moves[i + 2]) > 2) || (abs(moves[i + 1] - moves[i + 3])) > 2)
			return "You can't move more than two squares";
		if (moves.size() > 4 && ((abs(moves[i] - moves[i + 2]) == 1) && (abs(moves[i + 1] - moves[i + 3])) == 1))
			return "You only get extra moves if you are jumping.";
	}
	return "";
}

std::vector<int> Checkers::moveConvert(std::string str)
{
	std::vector<int> moveList;

	for (int i = 0; i < str.length(); i++)
	{
		if ((str[i] >= 49) && (str[i] <= 57))
			moveList.push_back((str[i] - 49));
		else if ((str[i] >= 65) && (str[i] <= 72))
			moveList.push_back(str[i] - 65);
		else if ((str[i] >= 97) && (str[i] <= 104))
			moveList.push_back(str[i] - 97);
	}
	return moveList;
}

void Checkers::move(std::vector<int> moves)
{
	for (int i = 0; i < moves.size() - 2; i = i + 2)
	{
		if ((abs(moves[i] - moves[i + 2]) == 2) && (abs(moves[i + 1] - moves[i + 3])) == 2)
			deletePiece((moves[i] + moves[i + 2]) / 2, (moves[i + 1] + moves[i + 3]) / 2);
		if (moves[i + 3] == 0 || moves[i + 3] == 7)
		{
			Piece* piece1 = pBoard->getPiecePointer(moves[0], moves[1]);
			piece1->promoteKing();
			piece1->uniqueID = piece1->uniqueID - 32;
		}
	}
	movePiece(moves[0], moves[1], moves[moves.size() - 2], moves[moves.size() - 1]);
}