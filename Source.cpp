#include <iostream>
#include "Piece.h"
#include "Player.h"
#include "Square.h"
#include "Board.h"
#include "Checkers.h"
#include <string>
using namespace std;


int main()
{
	cout << "Welcome to Checkers!" << endl;
	cout << "To move, input the location of the piece you want to move (e.g. C3), followed by where you want the piece to go.";
	Checkers checkers;
	checkers.createCheckerPieces();
	bool player1 = true;
	string moveList = "";
	bool exit = false;

	while (exit == false) 
	{
		bool trigger = true;
		checkers.displayBoard();
		do
		{
			if (player1)
				cout << endl << "Player 1's move: ";
			else
				cout << endl << "Player 2's move: ";
			cin >> moveList;
			if (moveList == "exit")
			{
				exit = true;
				trigger = false;
			}
			else
			{
				vector<int> moveVector = checkers.moveConvert(moveList);
				string moveCheckCode = checkers.moveCheck(player1, moveVector);
				if (moveCheckCode == "")
				{
					checkers.move(moveVector);
					trigger = false;
				}
				else
					cout << endl << moveCheckCode;
			}
		} while (trigger);
	player1 = not player1;
	}
	

	checkers.movePiece(0, 0, 0, 4);
	checkers.displayBoard();
	checkers.deletePiece(0, 4);
	checkers.displayBoard();


	cout << "stop";
}