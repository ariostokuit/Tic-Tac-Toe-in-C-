#pragma once
#include <iostream>
using namespace std;

const int SPACESR = 3; //SIZE OF ROW
const int SPACESC = 3; //SIZE OF COLUMN
class TicTacToe {
private:
	char BoardArr[SPACESR][SPACESC];
public:
	TicTacToe();
	void createBoard();
	void updatePosition(int, int, char);
	void resetBoard();
	bool testPosition(int, int);
	bool findWinner(char);
	bool CatsGame();	
};

TicTacToe::TicTacToe() { //initialize the Board with asterisk as empty spaces
	for (int r = 0; r < SPACESR; r++) {
		for (int c = 0; c < SPACESC; c++)
		{
			BoardArr[r][c] = '*';
		}
	}
}
void TicTacToe::createBoard() { //create and update the board
	cout << BoardArr[0][0] << "|" << BoardArr[0][1] << "|" << BoardArr[0][2] << endl;
	cout << "-----\n";
	cout << BoardArr[1][0] << "|" << BoardArr[1][1] << "|" << BoardArr[1][2] << endl;
	cout << "-----\n";
	cout << BoardArr[2][0] << "|" << BoardArr[2][1] << "|" << BoardArr[2][2] << endl;
}

//updates the board position
void TicTacToe::updatePosition(int r, int c, char player) { BoardArr[r][c] = player; } //update teh board
bool TicTacToe::testPosition(int r, int c) { //test if position is appropriate to play
	if (r < SPACESR && c < SPACESC) {
		if (BoardArr[r][c] == '*') {
			return true;
		}
		else return false;
	}
	else return false;
}
bool TicTacToe::findWinner(char player) { //Find winner based on player's character
	if ((BoardArr[0][0] == player && BoardArr[0][1] == player) && BoardArr[0][2] == player)
	{return true;} // searches matches on row 0
	if ((BoardArr[1][0] == player && BoardArr[1][1] == player) && BoardArr[1][2] == player)
	{return true;} //searches matches on row 1
	if ((BoardArr[2][0] == player && BoardArr[2][1] == player) && BoardArr[2][2] == player)
	{return true;} //search matches on row 2
	if((BoardArr[0][0] == player && BoardArr[1][0] == player) && BoardArr[2][0]== player)
	{return true;} //check matches on col0
	if ((BoardArr[0][1] == player && BoardArr[1][1] == player) && BoardArr[2][1] == player)
	{return true;} // check matches on col1
	if ((BoardArr[0][2] == player && BoardArr[1][2] == player) && BoardArr[2][2] == player) 
	{return true; } //check mathces on col2
	if((BoardArr[0][0] == player && BoardArr[1][1] == player) && BoardArr[2][2] == player)
	{return true;}
	if ((BoardArr[0][2] == player && BoardArr[1][1] == player) && BoardArr[2][0] == player)
	{return true;}
	else return false;
}

bool TicTacToe::CatsGame() { 
	bool isCatGame = true;
	for (int r = 0; r < SPACESR; r++) {
		for (int c = 0; c < SPACESC; c++) {
			if (BoardArr[r][c] == '*') { return false; } //if there is a character that is empty then it is false
		}
	}
	return isCatGame;
}

void TicTacToe::resetBoard() { //the loop will change the entire board to be empty
	for (int r = 0; r < SPACESR; r++) {
		for (int c = 0; c < SPACESC; c++) {
			BoardArr[r][c] = '*';
		}	
	}
}