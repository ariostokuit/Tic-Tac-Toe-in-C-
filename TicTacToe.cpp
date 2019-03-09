// TicTacToe.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include "TicTacToe.h"
using namespace std;

void updatePlayer(TicTacToe &game, char player) { //ask and update player1 moves
	int r, c;
	bool invalidInput = true;
		do { //will keep repeating if the player input is unacceptable
			cout << "Player " << player << " turn\n";
			cout << "Enter a position by row:";
			cin >> r;
			cout << "Enter a position by col:";
			cin >> c;
			if (game.testPosition(r, c) == true) {
				game.updatePosition(r, c, player);
			invalidInput = false;
			}
			else {
				cout << "Invalid Input\n";
			}
		} while (invalidInput);
}
//announce the winner function
void AnnounceWinner(char winner) {cout << "Player " << winner << " is the winner\n";}

char AskPlayAgain() { //can be used to ask the player if they want to play again
	char input;
	cout << "Do you want to play again?(y or n):";
	cin >> input;
	return input;
}
int main()
{
	const char player1 = 'X';
	const char player2 = 'O';
	TicTacToe game;
	bool isCatGame = game.CatsGame();
	bool WinnerFound = true;
	char winner;
	char PlayAgain = 'y';

	while (PlayAgain == 'y' || PlayAgain == 'Y') {
		do {
			game.createBoard();
			updatePlayer(game, player1);
			game.createBoard();
			if (game.findWinner(player1) == true) {
				winner = player1;
				break;
			}
			updatePlayer(game, player2);
			if (game.findWinner(player2) == true) {
				winner = player2;
				break;
			}
			isCatGame = game.CatsGame(); //test if there is no winner
		} while (isCatGame == false);

		if (isCatGame) { cout << "Cat's Game\n"; } //announce cat's game
		AnnounceWinner(winner);	//else announce winner
		PlayAgain = AskPlayAgain();
		if (PlayAgain == 'y' || PlayAgain == 'Y') { game.resetBoard(); } //will reset the board to play again
	}
	
	
	return 0;
}