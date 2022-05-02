#ifndef PLAYER_H
#define PLAYER_H

class Player
{
private:
	int playerNum;
	char playerChar;

public:
	Player(int x);
	void setPlayerChar(char playerChar);
	char getPlayerChar();
};
#endif


