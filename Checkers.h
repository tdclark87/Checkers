#ifndef CHECKERS_H
#define CHECKERS_H
#include "Board.h"

#include <vector>
#include <string>
using namespace std;

class Checkers
{
private:
	Board *pBoard;

public:
	void createCheckerPieces();
	void displayBoard();
	void movePiece(int x, int y, int a, int b);
	void move(vector<int> moves);
	void deletePiece(int x, int y);
	bool moveCheckPiece(bool player1, vector<int> moves);
	string moveCheck(bool player1, vector<int> moves);
	vector<int> moveConvert(string str);
	Checkers();
};

#endif // !'CHECKERS_H'


